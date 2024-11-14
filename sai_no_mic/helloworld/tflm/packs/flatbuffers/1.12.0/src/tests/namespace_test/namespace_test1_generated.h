// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_NAMESPACETEST1_NAMESPACEA_NAMESPACEB_H_
#define FLATBUFFERS_GENERATED_NAMESPACETEST1_NAMESPACEA_NAMESPACEB_H_

#include "flatbuffers/flatbuffers.h"

namespace NamespaceA {
namespace NamespaceB {

struct TableInNestedNS;
struct TableInNestedNSBuilder;
struct TableInNestedNST;

struct StructInNestedNS;

bool operator==(const TableInNestedNST &lhs, const TableInNestedNST &rhs);
bool operator!=(const TableInNestedNST &lhs, const TableInNestedNST &rhs);
bool operator==(const StructInNestedNS &lhs, const StructInNestedNS &rhs);
bool operator!=(const StructInNestedNS &lhs, const StructInNestedNS &rhs);

inline const flatbuffers::TypeTable *TableInNestedNSTypeTable();

inline const flatbuffers::TypeTable *StructInNestedNSTypeTable();

enum EnumInNestedNS {
  EnumInNestedNS_A = 0,
  EnumInNestedNS_B = 1,
  EnumInNestedNS_C = 2,
  EnumInNestedNS_MIN = EnumInNestedNS_A,
  EnumInNestedNS_MAX = EnumInNestedNS_C
};

inline const EnumInNestedNS (&EnumValuesEnumInNestedNS())[3] {
  static const EnumInNestedNS values[] = {
    EnumInNestedNS_A,
    EnumInNestedNS_B,
    EnumInNestedNS_C
  };
  return values;
}

inline const char * const *EnumNamesEnumInNestedNS() {
  static const char * const names[4] = {
    "A",
    "B",
    "C",
    nullptr
  };
  return names;
}

inline const char *EnumNameEnumInNestedNS(EnumInNestedNS e) {
  if (flatbuffers::IsOutRange(e, EnumInNestedNS_A, EnumInNestedNS_C)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesEnumInNestedNS()[index];
}

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) StructInNestedNS FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t a_;
  int32_t b_;

 public:
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return StructInNestedNSTypeTable();
  }
  StructInNestedNS()
      : a_(0),
        b_(0) {
  }
  StructInNestedNS(int32_t _a, int32_t _b)
      : a_(flatbuffers::EndianScalar(_a)),
        b_(flatbuffers::EndianScalar(_b)) {
  }
  int32_t a() const {
    return flatbuffers::EndianScalar(a_);
  }
  void mutate_a(int32_t _a) {
    flatbuffers::WriteScalar(&a_, _a);
  }
  int32_t b() const {
    return flatbuffers::EndianScalar(b_);
  }
  void mutate_b(int32_t _b) {
    flatbuffers::WriteScalar(&b_, _b);
  }
};
FLATBUFFERS_STRUCT_END(StructInNestedNS, 8);

inline bool operator==(const StructInNestedNS &lhs, const StructInNestedNS &rhs) {
  return
      (lhs.a() == rhs.a()) &&
      (lhs.b() == rhs.b());
}

inline bool operator!=(const StructInNestedNS &lhs, const StructInNestedNS &rhs) {
    return !(lhs == rhs);
}


struct TableInNestedNST : public flatbuffers::NativeTable {
  typedef TableInNestedNS TableType;
  int32_t foo;
  TableInNestedNST()
      : foo(0) {
  }
};

inline bool operator==(const TableInNestedNST &lhs, const TableInNestedNST &rhs) {
  return
      (lhs.foo == rhs.foo);
}

inline bool operator!=(const TableInNestedNST &lhs, const TableInNestedNST &rhs) {
    return !(lhs == rhs);
}


struct TableInNestedNS FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TableInNestedNST NativeTableType;
  typedef TableInNestedNSBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return TableInNestedNSTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_FOO = 4
  };
  int32_t foo() const {
    return GetField<int32_t>(VT_FOO, 0);
  }
  bool mutate_foo(int32_t _foo) {
    return SetField<int32_t>(VT_FOO, _foo, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_FOO) &&
           verifier.EndTable();
  }
  TableInNestedNST *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(TableInNestedNST *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<TableInNestedNS> Pack(flatbuffers::FlatBufferBuilder &_fbb, const TableInNestedNST* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct TableInNestedNSBuilder {
  typedef TableInNestedNS Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_foo(int32_t foo) {
    fbb_.AddElement<int32_t>(TableInNestedNS::VT_FOO, foo, 0);
  }
  explicit TableInNestedNSBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<TableInNestedNS> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TableInNestedNS>(end);
    return o;
  }
};

inline flatbuffers::Offset<TableInNestedNS> CreateTableInNestedNS(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t foo = 0) {
  TableInNestedNSBuilder builder_(_fbb);
  builder_.add_foo(foo);
  return builder_.Finish();
}

flatbuffers::Offset<TableInNestedNS> CreateTableInNestedNS(flatbuffers::FlatBufferBuilder &_fbb, const TableInNestedNST *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline TableInNestedNST *TableInNestedNS::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  flatbuffers::unique_ptr<NamespaceA::NamespaceB::TableInNestedNST> _o = flatbuffers::unique_ptr<NamespaceA::NamespaceB::TableInNestedNST>(new TableInNestedNST());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void TableInNestedNS::UnPackTo(TableInNestedNST *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = foo(); _o->foo = _e; }
}

inline flatbuffers::Offset<TableInNestedNS> TableInNestedNS::Pack(flatbuffers::FlatBufferBuilder &_fbb, const TableInNestedNST* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateTableInNestedNS(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<TableInNestedNS> CreateTableInNestedNS(flatbuffers::FlatBufferBuilder &_fbb, const TableInNestedNST *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const TableInNestedNST* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _foo = _o->foo;
  return NamespaceA::NamespaceB::CreateTableInNestedNS(
      _fbb,
      _foo);
}

inline const flatbuffers::TypeTable *EnumInNestedNSTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    NamespaceA::NamespaceB::EnumInNestedNSTypeTable
  };
  static const char * const names[] = {
    "A",
    "B",
    "C"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_ENUM, 3, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *TableInNestedNSTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_INT, 0, -1 }
  };
  static const char * const names[] = {
    "foo"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 1, type_codes, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *StructInNestedNSTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_INT, 0, -1 },
    { flatbuffers::ET_INT, 0, -1 }
  };
  static const int64_t values[] = { 0, 4, 8 };
  static const char * const names[] = {
    "a",
    "b"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_STRUCT, 2, type_codes, nullptr, values, names
  };
  return &tt;
}

}  // namespace NamespaceB
}  // namespace NamespaceA

#endif  // FLATBUFFERS_GENERATED_NAMESPACETEST1_NAMESPACEA_NAMESPACEB_H_