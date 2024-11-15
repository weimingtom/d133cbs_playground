/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "fft_util.h"

#include <stdio.h>

#define FIXED_POINT 16
#include "kiss_fft.h"
#include "tools/kiss_fftr.h"

#if defined(TF_LITE_STATIC_MEMORY)
#include <stdio.h> 
#include "malloc.h"
#define malloc(x) mymalloc(SRAMIN, x)
#define free(x) myfree(SRAMIN, x)
#endif

int FftPopulateState(struct FftState* state, size_t input_size) {
  state->input_size = input_size;
  state->fft_size = 1;
  while (state->fft_size < state->input_size) {
    state->fft_size <<= 1;
  }

  state->input = reinterpret_cast<int16_t*>(
      malloc(state->fft_size * sizeof(*state->input)));
  if (state->input == nullptr) {
#if !defined(TF_LITE_STATIC_MEMORY)  
    fprintf(stderr, "Failed to alloc fft input buffer\n");
#else
    printf("Failed to alloc fft input buffer\n");
#endif    
    return 0;
  }

  state->output = reinterpret_cast<complex_int16_t*>(
      malloc((state->fft_size / 2 + 1) * sizeof(*state->output) * 2));
  if (state->output == nullptr) {
#if !defined(TF_LITE_STATIC_MEMORY)  
    fprintf(stderr, "Failed to alloc fft output buffer\n");
#else
    printf("Failed to alloc fft output buffer\n");	
#endif    
    return 0;
  }

  // Ask kissfft how much memory it wants.
  size_t scratch_size = 0;
  kiss_fftr_cfg kfft_cfg = kiss_fftr_alloc(
      state->fft_size, 0, nullptr, &scratch_size);
  if (kfft_cfg != nullptr) {
#if !defined(TF_LITE_STATIC_MEMORY)  
    fprintf(stderr, "Kiss memory sizing failed.\n");
#else
    printf("Kiss memory sizing failed.\n");		
#endif    
    return 0;
  }
  state->scratch = malloc(scratch_size);
  if (state->scratch == nullptr) {
#if !defined(TF_LITE_STATIC_MEMORY)  
    fprintf(stderr, "Failed to alloc fft scratch buffer\n");
#else
    printf("Failed to alloc fft scratch buffer\n");	
#endif    
    return 0;
  }
  state->scratch_size = scratch_size;
  // Let kissfft configure the scratch space we just allocated
  kfft_cfg = kiss_fftr_alloc(state->fft_size, 0,
                                              state->scratch, &scratch_size);
  if (kfft_cfg != state->scratch) {
#if !defined(TF_LITE_STATIC_MEMORY)  
    fprintf(stderr, "Kiss memory preallocation strategy failed.\n");
#else
    printf("Kiss memory preallocation strategy failed.\n");
#endif    
    return 0;
  }
  return 1;
}

void FftFreeStateContents(struct FftState* state) {
  free(state->input);
  free(state->output);
  free(state->scratch);
}
