#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/code-factory.h"
#include "src/elements-kind.h"
#include "src/heap/factory-inl.h"
#include "src/objects.h"
#include "builtins-typed-array-from-dsl-gen.h"

namespace v8 {
namespace internal {

using Node = compiler::Node;

compiler::TNode<Number> TypedArrayBuiltinsFromDSLAssembler::CallCompareWithDetachedCheck(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<JSReceiver> p_comparefn, TNode<Object> p_a, TNode<Object> p_b, Label* label_Detached_88) {
  Node* return_default = &*SmiConstant(0);
  TVARIABLE(Number, _return73_impl);
  auto _return73 = &_return73_impl;
  USE(_return73);
  *_return73 = UncheckedCast<Number>(return_default);
  Label label_macro_end_226_impl(this, {_return73});
  Label* label_macro_end_226 = &label_macro_end_226_impl;
  USE(label_macro_end_226);
  {
    TNode<Object> t297 = UncheckedCast<Object>(Call(p_context, p_comparefn, UndefinedConstant(), p_a, p_b));
    USE(t297);
    TNode<Number> t298 = UncheckedCast<Number>(ToNumber_Inline(p_context, t297));
    USE(t298);
    TVARIABLE(Number, v74_impl);
    auto v74 = &v74_impl;
    USE(v74);
    *v74 = t298;
    {
      Label label__True_89_impl(this);
      Label* label__True_89 = &label__True_89_impl;
      USE(label__True_89);
      Label label__False_90_impl(this, {});
      Label* label__False_90 = &label__False_90_impl;
      USE(label__False_90);
      TNode<JSArrayBuffer> t299 = UncheckedCast<JSArrayBuffer>(LoadTypedArrayBuffer(p_array));
      TNode<BoolT> t300 = UncheckedCast<BoolT>(IsDetachedBuffer(t299));
      USE(t300);
      Branch(t300, label__True_89, label__False_90);
      if (label__True_89->is_used())
      {
        BIND(label__True_89);
        Goto(label_Detached_88);
      }
      BIND(label__False_90);
    }
    {
      Label label__True_91_impl(this);
      Label* label__True_91 = &label__True_91_impl;
      USE(label__True_91);
      Label label__False_92_impl(this, {_return73});
      Label* label__False_92 = &label__False_92_impl;
      USE(label__False_92);
      TNode<BoolT> t301 = UncheckedCast<BoolT>(NumberIsNaN(v74->value()));
      USE(t301);
      Branch(t301, label__True_91, label__False_92);
      if (label__True_91->is_used())
      {
        BIND(label__True_91);
        int32_t t302 = 0;
        TNode<Smi> t303 = UncheckedCast<Smi>(SmiConstant(t302));
        *_return73 = t303;
        Goto(label_macro_end_226);
      }
      BIND(label__False_92);
    }
    *_return73 = v74->value();
    Goto(label_macro_end_226);
  }
  BIND(label_macro_end_226);
  return _return73->value();
}

compiler::TNode<Object> TypedArrayBuiltinsFromDSLAssembler::Load(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<Smi> p_kind, TNode<Smi> p_index) {
  Node* return_default = &*SmiConstant(0);
  TVARIABLE(Object, _return75_impl);
  auto _return75 = &_return75_impl;
  USE(_return75);
  *_return75 = UncheckedCast<Object>(return_default);
  Label label_macro_end_227_impl(this, {_return75});
  Label* label_macro_end_227 = &label_macro_end_227_impl;
  USE(label_macro_end_227);
  {
    TNode<Object> t304 = UncheckedCast<Object>(CallBuiltin(Builtins::kTypedArrayLoadElementAsTagged, p_context, p_array, p_kind, p_index));
    USE(t304);
    *_return75 = t304;
    Goto(label_macro_end_227);
  }
  BIND(label_macro_end_227);
  return _return75->value();
}

void TypedArrayBuiltinsFromDSLAssembler::Store(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<Smi> p_kind, TNode<Smi> p_index, TNode<Object> p_value) {
  Label label_macro_end_228_impl(this, {});
  Label* label_macro_end_228 = &label_macro_end_228_impl;
  USE(label_macro_end_228);
  {
    CallBuiltin(Builtins::kTypedArrayStoreElementFromTagged, p_context, p_array, p_kind, p_index, p_value);
  }
}

void TypedArrayBuiltinsFromDSLAssembler::TypedArrayInsertionSort(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<Smi> p_kind, TNode<Smi> p_from_arg, TNode<Smi> p_to_arg, TNode<JSReceiver> p_comparefn, Label* label_Detached_93) {
  Label label_macro_end_229_impl(this, {});
  Label* label_macro_end_229 = &label_macro_end_229_impl;
  USE(label_macro_end_229);
  {
    TVARIABLE(Smi, from76_impl);
    auto from76 = &from76_impl;
    USE(from76);
    *from76 = p_from_arg;
    TVARIABLE(Smi, to77_impl);
    auto to77 = &to77_impl;
    USE(to77);
    *to77 = p_to_arg;
    {
      Label label__True_94_impl(this);
      Label* label__True_94 = &label__True_94_impl;
      USE(label__True_94);
      Label label__False_95_impl(this, {});
      Label* label__False_95 = &label__False_95_impl;
      USE(label__False_95);
      TNode<JSArrayBuffer> t305 = UncheckedCast<JSArrayBuffer>(LoadTypedArrayBuffer(p_array));
      TNode<BoolT> t306 = UncheckedCast<BoolT>(IsDetachedBuffer(t305));
      USE(t306);
      Branch(t306, label__True_94, label__False_95);
      if (label__True_94->is_used())
      {
        BIND(label__True_94);
        Goto(label_Detached_93);
      }
      BIND(label__False_95);
    }
    int32_t t307 = 1;
    TNode<Smi> t308 = UncheckedCast<Smi>(SmiConstant(t307));
    TNode<Smi> t309 = UncheckedCast<Smi>(SmiAdd(from76->value(), t308));
    TVARIABLE(Smi, i78_impl);
    auto i78 = &i78_impl;
    USE(i78);
    *i78 = t309;
    Label label__True_96_impl(this);
    Label* label__True_96 = &label__True_96_impl;
    USE(label__True_96);
    Label label__False_97_impl(this);
    Label* label__False_97 = &label__False_97_impl;
    USE(label__False_97);
    Label label_header_180_230_impl(this, {i78});
    Label* label_header_180_230 = &label_header_180_230_impl;
    USE(label_header_180_230);
    Goto(label_header_180_230);
    BIND(label_header_180_230);
    Label label_assignment_181_231_impl(this);
    Label* label_assignment_181_231 = &label_assignment_181_231_impl;
    USE(label_assignment_181_231);
    TNode<BoolT> t310 = UncheckedCast<BoolT>(SmiLessThan(i78->value(), to77->value()));
    Branch(t310, label__True_96, label__False_97);
    if (label__True_96->is_used())
    {
      BIND(label__True_96);
      {
        TNode<Object> t311 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, i78->value()));
        USE(t311);
        TVARIABLE(Object, element79_impl);
        auto element79 = &element79_impl;
        USE(element79);
        *element79 = t311;
        int32_t t312 = 1;
        TNode<Smi> t313 = UncheckedCast<Smi>(SmiConstant(t312));
        TNode<Smi> t314 = UncheckedCast<Smi>(SmiSub(i78->value(), t313));
        TVARIABLE(Smi, j80_impl);
        auto j80 = &j80_impl;
        USE(j80);
        *j80 = t314;
        Label label__True_98_impl(this);
        Label* label__True_98 = &label__True_98_impl;
        USE(label__True_98);
        Label label__False_99_impl(this);
        Label* label__False_99 = &label__False_99_impl;
        USE(label__False_99);
        Label label_header_182_232_impl(this, {j80});
        Label* label_header_182_232 = &label_header_182_232_impl;
        USE(label_header_182_232);
        Goto(label_header_182_232);
        BIND(label_header_182_232);
        Label label_assignment_183_233_impl(this);
        Label* label_assignment_183_233 = &label_assignment_183_233_impl;
        USE(label_assignment_183_233);
        TNode<BoolT> t315 = UncheckedCast<BoolT>(SmiGreaterThanOrEqual(j80->value(), from76->value()));
        Branch(t315, label__True_98, label__False_99);
        if (label__True_98->is_used())
        {
          BIND(label__True_98);
          {
            TNode<Object> t316 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, j80->value()));
            USE(t316);
            TVARIABLE(Object, tmp81_impl);
            auto tmp81 = &tmp81_impl;
            USE(tmp81);
            *tmp81 = t316;
            TNode<Number> t317 = UncheckedCast<Number>(CallCompareWithDetachedCheck(p_context, p_array, p_comparefn, tmp81->value(), element79->value(), label_Detached_93));
            USE(t317);
            TVARIABLE(Number, order82_impl);
            auto order82 = &order82_impl;
            USE(order82);
            *order82 = t317;
            {
              Label label__True_100_impl(this);
              Label* label__True_100 = &label__True_100_impl;
              USE(label__True_100);
              Label label__False_101_impl(this);
              Label* label__False_101 = &label__False_101_impl;
              USE(label__False_101);
              Label label_if_done_label_184_234_impl(this, {});
              Label* label_if_done_label_184_234 = &label_if_done_label_184_234_impl;
              USE(label_if_done_label_184_234);
              int32_t t318 = 0;
              TNode<Smi> t319 = UncheckedCast<Smi>(SmiConstant(t318));
              BranchIfNumberGreaterThan(order82->value(), t319, label__True_100, label__False_101);
              if (label__True_100->is_used())
              {
                BIND(label__True_100);
                {
                  int32_t t320 = 1;
                  TNode<Smi> t321 = UncheckedCast<Smi>(SmiConstant(t320));
                  TNode<Smi> t322 = UncheckedCast<Smi>(SmiAdd(j80->value(), t321));
                  Store(p_context, p_array, p_kind, t322, tmp81->value());
                }
                Goto(label_if_done_label_184_234);
              }
              if (label__False_101->is_used())
              {
                BIND(label__False_101);
                {
                  Goto(label__False_99);
                }
              }
              BIND(label_if_done_label_184_234);
            }
          }
          Goto(label_assignment_183_233);
        }
        {
          BIND(label_assignment_183_233);
          TNode<Smi> t323 = UncheckedCast<Smi>(SmiConstant(1));
          TNode<Smi> t324 = UncheckedCast<Smi>(SmiSub(j80->value(), t323));
          *j80 = t324;
          Goto(label_header_182_232);
        }
        BIND(label__False_99);
        int32_t t325 = 1;
        TNode<Smi> t326 = UncheckedCast<Smi>(SmiConstant(t325));
        TNode<Smi> t327 = UncheckedCast<Smi>(SmiAdd(j80->value(), t326));
        Store(p_context, p_array, p_kind, t327, element79->value());
      }
      Goto(label_assignment_181_231);
    }
    {
      BIND(label_assignment_181_231);
      TNode<Smi> t328 = UncheckedCast<Smi>(SmiConstant(1));
      TNode<Smi> t329 = UncheckedCast<Smi>(SmiAdd(i78->value(), t328));
      *i78 = t329;
      Goto(label_header_180_230);
    }
    BIND(label__False_97);
  }
}

void TypedArrayBuiltinsFromDSLAssembler::TypedArrayQuickSortImpl(TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<Smi> p_kind, TNode<Smi> p_from_arg, TNode<Smi> p_to_arg, TNode<JSReceiver> p_comparefn, Label* label_Detached_102) {
  Label label_macro_end_235_impl(this, {});
  Label* label_macro_end_235 = &label_macro_end_235_impl;
  USE(label_macro_end_235);
  {
    TVARIABLE(Smi, from83_impl);
    auto from83 = &from83_impl;
    USE(from83);
    *from83 = p_from_arg;
    TVARIABLE(Smi, to84_impl);
    auto to84 = &to84_impl;
    USE(to84);
    *to84 = p_to_arg;
    {
      Label label__True_103_impl(this);
      Label* label__True_103 = &label__True_103_impl;
      USE(label__True_103);
      Label label__False_104_impl(this);
      Label* label__False_104 = &label__False_104_impl;
      USE(label__False_104);
      Label label_header_185_236_impl(this, {from83, to84});
      Label* label_header_185_236 = &label_header_185_236_impl;
      USE(label_header_185_236);
      Goto(label_header_185_236);
      BIND(label_header_185_236);
      TNode<Smi> t330 = UncheckedCast<Smi>(SmiSub(to84->value(), from83->value()));
      int32_t t331 = 1;
      TNode<Smi> t332 = UncheckedCast<Smi>(SmiConstant(t331));
      TNode<BoolT> t333 = UncheckedCast<BoolT>(SmiGreaterThan(t330, t332));
      Branch(t333, label__True_103, label__False_104);
      if (label__True_103->is_used())
      {
        BIND(label__True_103);
        {
          {
            Label label__True_105_impl(this);
            Label* label__True_105 = &label__True_105_impl;
            USE(label__True_105);
            Label label__False_106_impl(this, {});
            Label* label__False_106 = &label__False_106_impl;
            USE(label__False_106);
            TNode<Smi> t334 = UncheckedCast<Smi>(SmiSub(to84->value(), from83->value()));
            int32_t t335 = 10;
            TNode<Smi> t336 = UncheckedCast<Smi>(SmiConstant(t335));
            TNode<BoolT> t337 = UncheckedCast<BoolT>(SmiLessThanOrEqual(t334, t336));
            Branch(t337, label__True_105, label__False_106);
            if (label__True_105->is_used())
            {
              BIND(label__True_105);
              {
                TypedArrayInsertionSort(p_context, p_array, p_kind, from83->value(), to84->value(), p_comparefn, label_Detached_102);
                Goto(label__False_104);
              }
            }
            BIND(label__False_106);
          }
          TNode<Smi> t338 = UncheckedCast<Smi>(SmiSub(to84->value(), from83->value()));
          int32_t t339 = 1;
          TNode<Smi> t340 = UncheckedCast<Smi>(SmiShr(t338, t339));
          TNode<Smi> t341 = UncheckedCast<Smi>(SmiAdd(from83->value(), t340));
          TVARIABLE(Smi, third_index85_impl);
          auto third_index85 = &third_index85_impl;
          USE(third_index85);
          *third_index85 = t341;
          {
            Label label__True_107_impl(this);
            Label* label__True_107 = &label__True_107_impl;
            USE(label__True_107);
            Label label__False_108_impl(this, {});
            Label* label__False_108 = &label__False_108_impl;
            USE(label__False_108);
            TNode<JSArrayBuffer> t342 = UncheckedCast<JSArrayBuffer>(LoadTypedArrayBuffer(p_array));
            TNode<BoolT> t343 = UncheckedCast<BoolT>(IsDetachedBuffer(t342));
            USE(t343);
            Branch(t343, label__True_107, label__False_108);
            if (label__True_107->is_used())
            {
              BIND(label__True_107);
              Goto(label_Detached_102);
            }
            BIND(label__False_108);
          }
          TNode<Object> t344 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, from83->value()));
          USE(t344);
          TVARIABLE(Object, v086_impl);
          auto v086 = &v086_impl;
          USE(v086);
          *v086 = t344;
          int32_t t345 = 1;
          TNode<Smi> t346 = UncheckedCast<Smi>(SmiConstant(t345));
          TNode<Smi> t347 = UncheckedCast<Smi>(SmiSub(to84->value(), t346));
          TNode<Object> t348 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, t347));
          USE(t348);
          TVARIABLE(Object, v187_impl);
          auto v187 = &v187_impl;
          USE(v187);
          *v187 = t348;
          TNode<Object> t349 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, third_index85->value()));
          USE(t349);
          TVARIABLE(Object, v288_impl);
          auto v288 = &v288_impl;
          USE(v288);
          *v288 = t349;
          TNode<Number> t350 = UncheckedCast<Number>(CallCompareWithDetachedCheck(p_context, p_array, p_comparefn, v086->value(), v187->value(), label_Detached_102));
          USE(t350);
          TVARIABLE(Number, c0189_impl);
          auto c0189 = &c0189_impl;
          USE(c0189);
          *c0189 = t350;
          {
            Label label__True_109_impl(this);
            Label* label__True_109 = &label__True_109_impl;
            USE(label__True_109);
            Label label__False_110_impl(this, {v086, v187});
            Label* label__False_110 = &label__False_110_impl;
            USE(label__False_110);
            int32_t t351 = 0;
            TNode<Smi> t352 = UncheckedCast<Smi>(SmiConstant(t351));
            BranchIfNumberGreaterThan(c0189->value(), t352, label__True_109, label__False_110);
            if (label__True_109->is_used())
            {
              BIND(label__True_109);
              {
                TVARIABLE(Object, tmp90_impl);
                auto tmp90 = &tmp90_impl;
                USE(tmp90);
                *tmp90 = v086->value();
                *v086 = v187->value();
                *v187 = tmp90->value();
              }
              Goto(label__False_110);
            }
            BIND(label__False_110);
          }
          TNode<Number> t353 = UncheckedCast<Number>(CallCompareWithDetachedCheck(p_context, p_array, p_comparefn, v086->value(), v288->value(), label_Detached_102));
          USE(t353);
          TVARIABLE(Number, c0291_impl);
          auto c0291 = &c0291_impl;
          USE(c0291);
          *c0291 = t353;
          {
            Label label__True_111_impl(this);
            Label* label__True_111 = &label__True_111_impl;
            USE(label__True_111);
            Label label__False_112_impl(this);
            Label* label__False_112 = &label__False_112_impl;
            USE(label__False_112);
            Label label_if_done_label_186_237_impl(this, {v086, v187, v288});
            Label* label_if_done_label_186_237 = &label_if_done_label_186_237_impl;
            USE(label_if_done_label_186_237);
            int32_t t354 = 0;
            TNode<Smi> t355 = UncheckedCast<Smi>(SmiConstant(t354));
            BranchIfNumberGreaterThanOrEqual(c0291->value(), t355, label__True_111, label__False_112);
            if (label__True_111->is_used())
            {
              BIND(label__True_111);
              {
                TVARIABLE(Object, tmp92_impl);
                auto tmp92 = &tmp92_impl;
                USE(tmp92);
                *tmp92 = v086->value();
                *v086 = v288->value();
                *v288 = v187->value();
                *v187 = tmp92->value();
              }
              Goto(label_if_done_label_186_237);
            }
            if (label__False_112->is_used())
            {
              BIND(label__False_112);
              {
                TNode<Number> t356 = UncheckedCast<Number>(CallCompareWithDetachedCheck(p_context, p_array, p_comparefn, v187->value(), v288->value(), label_Detached_102));
                USE(t356);
                TVARIABLE(Number, c1293_impl);
                auto c1293 = &c1293_impl;
                USE(c1293);
                *c1293 = t356;
                {
                  Label label__True_113_impl(this);
                  Label* label__True_113 = &label__True_113_impl;
                  USE(label__True_113);
                  Label label__False_114_impl(this, {v187, v288});
                  Label* label__False_114 = &label__False_114_impl;
                  USE(label__False_114);
                  int32_t t357 = 0;
                  TNode<Smi> t358 = UncheckedCast<Smi>(SmiConstant(t357));
                  BranchIfNumberGreaterThan(c1293->value(), t358, label__True_113, label__False_114);
                  if (label__True_113->is_used())
                  {
                    BIND(label__True_113);
                    {
                      TVARIABLE(Object, tmp94_impl);
                      auto tmp94 = &tmp94_impl;
                      USE(tmp94);
                      *tmp94 = v187->value();
                      *v187 = v288->value();
                      *v288 = tmp94->value();
                    }
                    Goto(label__False_114);
                  }
                  BIND(label__False_114);
                }
              }
              Goto(label_if_done_label_186_237);
            }
            BIND(label_if_done_label_186_237);
          }
          Store(p_context, p_array, p_kind, from83->value(), v086->value());
          int32_t t359 = 1;
          TNode<Smi> t360 = UncheckedCast<Smi>(SmiConstant(t359));
          TNode<Smi> t361 = UncheckedCast<Smi>(SmiSub(to84->value(), t360));
          Store(p_context, p_array, p_kind, t361, v288->value());
          TVARIABLE(Object, pivot95_impl);
          auto pivot95 = &pivot95_impl;
          USE(pivot95);
          *pivot95 = v187->value();
          int32_t t362 = 1;
          TNode<Smi> t363 = UncheckedCast<Smi>(SmiConstant(t362));
          TNode<Smi> t364 = UncheckedCast<Smi>(SmiAdd(from83->value(), t363));
          TVARIABLE(Smi, low_end96_impl);
          auto low_end96 = &low_end96_impl;
          USE(low_end96);
          *low_end96 = t364;
          int32_t t365 = 1;
          TNode<Smi> t366 = UncheckedCast<Smi>(SmiConstant(t365));
          TNode<Smi> t367 = UncheckedCast<Smi>(SmiSub(to84->value(), t366));
          TVARIABLE(Smi, high_start97_impl);
          auto high_start97 = &high_start97_impl;
          USE(high_start97);
          *high_start97 = t367;
          TNode<Object> t368 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, low_end96->value()));
          USE(t368);
          TVARIABLE(Object, low_end_value98_impl);
          auto low_end_value98 = &low_end_value98_impl;
          USE(low_end_value98);
          *low_end_value98 = t368;
          Store(p_context, p_array, p_kind, third_index85->value(), low_end_value98->value());
          Store(p_context, p_array, p_kind, low_end96->value(), pivot95->value());
          int32_t t369 = 1;
          TNode<Smi> t370 = UncheckedCast<Smi>(SmiConstant(t369));
          TNode<Smi> t371 = UncheckedCast<Smi>(SmiAdd(low_end96->value(), t370));
          TVARIABLE(Smi, idx99_impl);
          auto idx99 = &idx99_impl;
          USE(idx99);
          *idx99 = t371;
          Label label__True_115_impl(this);
          Label* label__True_115 = &label__True_115_impl;
          USE(label__True_115);
          Label label__False_116_impl(this);
          Label* label__False_116 = &label__False_116_impl;
          USE(label__False_116);
          Label label_header_187_238_impl(this, {low_end96, high_start97, low_end_value98, idx99});
          Label* label_header_187_238 = &label_header_187_238_impl;
          USE(label_header_187_238);
          Goto(label_header_187_238);
          BIND(label_header_187_238);
          Label label_assignment_188_239_impl(this);
          Label* label_assignment_188_239 = &label_assignment_188_239_impl;
          USE(label_assignment_188_239);
          TNode<BoolT> t372 = UncheckedCast<BoolT>(SmiLessThan(idx99->value(), high_start97->value()));
          Branch(t372, label__True_115, label__False_116);
          if (label__True_115->is_used())
          {
            BIND(label__True_115);
            {
              TNode<Object> t373 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, idx99->value()));
              USE(t373);
              TVARIABLE(Object, element100_impl);
              auto element100 = &element100_impl;
              USE(element100);
              *element100 = t373;
              TNode<Number> t374 = UncheckedCast<Number>(CallCompareWithDetachedCheck(p_context, p_array, p_comparefn, element100->value(), pivot95->value(), label_Detached_102));
              USE(t374);
              TVARIABLE(Number, order101_impl);
              auto order101 = &order101_impl;
              USE(order101);
              *order101 = t374;
              {
                Label label__True_117_impl(this);
                Label* label__True_117 = &label__True_117_impl;
                USE(label__True_117);
                Label label__False_118_impl(this);
                Label* label__False_118 = &label__False_118_impl;
                USE(label__False_118);
                Label label_if_done_label_189_240_impl(this, {low_end96, high_start97, low_end_value98, element100, order101});
                Label* label_if_done_label_189_240 = &label_if_done_label_189_240_impl;
                USE(label_if_done_label_189_240);
                int32_t t375 = 0;
                TNode<Smi> t376 = UncheckedCast<Smi>(SmiConstant(t375));
                BranchIfNumberLessThan(order101->value(), t376, label__True_117, label__False_118);
                if (label__True_117->is_used())
                {
                  BIND(label__True_117);
                  {
                    TNode<Object> t377 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, low_end96->value()));
                    USE(t377);
                    *low_end_value98 = t377;
                    Store(p_context, p_array, p_kind, idx99->value(), low_end_value98->value());
                    Store(p_context, p_array, p_kind, low_end96->value(), element100->value());
                    TNode<Smi> t378 = low_end96->value();
                    USE(t378);
                    TNode<Smi> t379 = UncheckedCast<Smi>(SmiConstant(1));
                    TNode<Smi> t380 = UncheckedCast<Smi>(SmiAdd(low_end96->value(), t379));
                    *low_end96 = t380;
                  }
                  Goto(label_if_done_label_189_240);
                }
                if (label__False_118->is_used())
                {
                  BIND(label__False_118);
                  {
                    Label label__True_119_impl(this);
                    Label* label__True_119 = &label__True_119_impl;
                    USE(label__True_119);
                    Label label__False_120_impl(this, {low_end96, high_start97, low_end_value98, element100, order101});
                    Label* label__False_120 = &label__False_120_impl;
                    USE(label__False_120);
                    int32_t t381 = 0;
                    TNode<Smi> t382 = UncheckedCast<Smi>(SmiConstant(t381));
                    BranchIfNumberGreaterThan(order101->value(), t382, label__True_119, label__False_120);
                    if (label__True_119->is_used())
                    {
                      BIND(label__True_119);
                      {
                        TVARIABLE(BoolT, break_for102_impl);
                        auto break_for102 = &break_for102_impl;
                        USE(break_for102);
                        TNode<BoolT> t383 = UncheckedCast<BoolT>(BoolConstant(false));
                        *break_for102 = t383;
                        {
                          Label label__True_121_impl(this);
                          Label* label__True_121 = &label__True_121_impl;
                          USE(label__True_121);
                          Label label__False_122_impl(this);
                          Label* label__False_122 = &label__False_122_impl;
                          USE(label__False_122);
                          Label label_header_190_241_impl(this, {high_start97, order101, break_for102});
                          Label* label_header_190_241 = &label_header_190_241_impl;
                          USE(label_header_190_241);
                          Goto(label_header_190_241);
                          BIND(label_header_190_241);
                          int32_t t384 = 0;
                          TNode<Smi> t385 = UncheckedCast<Smi>(SmiConstant(t384));
                          BranchIfNumberGreaterThan(order101->value(), t385, label__True_121, label__False_122);
                          if (label__True_121->is_used())
                          {
                            BIND(label__True_121);
                            {
                              TNode<Smi> t386 = high_start97->value();
                              USE(t386);
                              TNode<Smi> t387 = UncheckedCast<Smi>(SmiConstant(1));
                              TNode<Smi> t388 = UncheckedCast<Smi>(SmiSub(high_start97->value(), t387));
                              *high_start97 = t388;
                              {
                                Label label__True_123_impl(this);
                                Label* label__True_123 = &label__True_123_impl;
                                USE(label__True_123);
                                Label label__False_124_impl(this, {break_for102});
                                Label* label__False_124 = &label__False_124_impl;
                                USE(label__False_124);
                                TNode<BoolT> t389 = UncheckedCast<BoolT>(SmiEqual(high_start97->value(), idx99->value()));
                                Branch(t389, label__True_123, label__False_124);
                                if (label__True_123->is_used())
                                {
                                  BIND(label__True_123);
                                  {
                                    TNode<BoolT> t390 = UncheckedCast<BoolT>(BoolConstant(true));
                                    *break_for102 = t390;
                                    Goto(label__False_122);
                                  }
                                }
                                BIND(label__False_124);
                              }
                              TNode<Object> t391 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, high_start97->value()));
                              USE(t391);
                              TVARIABLE(Object, top_elem103_impl);
                              auto top_elem103 = &top_elem103_impl;
                              USE(top_elem103);
                              *top_elem103 = t391;
                              TNode<Number> t392 = UncheckedCast<Number>(CallCompareWithDetachedCheck(p_context, p_array, p_comparefn, top_elem103->value(), pivot95->value(), label_Detached_102));
                              USE(t392);
                              *order101 = t392;
                            }
                            Goto(label_header_190_241);
                          }
                          BIND(label__False_122);
                        }
                        {
                          Label label__True_125_impl(this);
                          Label* label__True_125 = &label__True_125_impl;
                          USE(label__True_125);
                          Label label__False_126_impl(this, {});
                          Label* label__False_126 = &label__False_126_impl;
                          USE(label__False_126);
                          Branch(break_for102->value(), label__True_125, label__False_126);
                          if (label__True_125->is_used())
                          {
                            BIND(label__True_125);
                            {
                              Goto(label__False_116);
                            }
                          }
                          BIND(label__False_126);
                        }
                        TNode<Object> t393 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, high_start97->value()));
                        USE(t393);
                        TVARIABLE(Object, high_start_value104_impl);
                        auto high_start_value104 = &high_start_value104_impl;
                        USE(high_start_value104);
                        *high_start_value104 = t393;
                        Store(p_context, p_array, p_kind, idx99->value(), high_start_value104->value());
                        Store(p_context, p_array, p_kind, high_start97->value(), element100->value());
                        {
                          Label label__True_127_impl(this);
                          Label* label__True_127 = &label__True_127_impl;
                          USE(label__True_127);
                          Label label__False_128_impl(this, {low_end96, low_end_value98, element100});
                          Label* label__False_128 = &label__False_128_impl;
                          USE(label__False_128);
                          int32_t t394 = 0;
                          TNode<Smi> t395 = UncheckedCast<Smi>(SmiConstant(t394));
                          BranchIfNumberLessThan(order101->value(), t395, label__True_127, label__False_128);
                          if (label__True_127->is_used())
                          {
                            BIND(label__True_127);
                            {
                              TNode<Object> t396 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, idx99->value()));
                              USE(t396);
                              *element100 = t396;
                              TNode<Object> t397 = UncheckedCast<Object>(Load(p_context, p_array, p_kind, low_end96->value()));
                              USE(t397);
                              *low_end_value98 = t397;
                              Store(p_context, p_array, p_kind, idx99->value(), low_end_value98->value());
                              Store(p_context, p_array, p_kind, low_end96->value(), element100->value());
                              TNode<Smi> t398 = low_end96->value();
                              USE(t398);
                              TNode<Smi> t399 = UncheckedCast<Smi>(SmiConstant(1));
                              TNode<Smi> t400 = UncheckedCast<Smi>(SmiAdd(low_end96->value(), t399));
                              *low_end96 = t400;
                            }
                            Goto(label__False_128);
                          }
                          BIND(label__False_128);
                        }
                      }
                      Goto(label__False_120);
                    }
                    BIND(label__False_120);
                  }
                  Goto(label_if_done_label_189_240);
                }
                BIND(label_if_done_label_189_240);
              }
            }
            Goto(label_assignment_188_239);
          }
          {
            BIND(label_assignment_188_239);
            TNode<Smi> t401 = idx99->value();
            USE(t401);
            TNode<Smi> t402 = UncheckedCast<Smi>(SmiConstant(1));
            TNode<Smi> t403 = UncheckedCast<Smi>(SmiAdd(idx99->value(), t402));
            *idx99 = t403;
            Goto(label_header_187_238);
          }
          BIND(label__False_116);
          {
            Label label__True_129_impl(this);
            Label* label__True_129 = &label__True_129_impl;
            USE(label__True_129);
            Label label__False_130_impl(this);
            Label* label__False_130 = &label__False_130_impl;
            USE(label__False_130);
            Label label_if_done_label_191_242_impl(this, {from83, to84});
            Label* label_if_done_label_191_242 = &label_if_done_label_191_242_impl;
            USE(label_if_done_label_191_242);
            TNode<Smi> t404 = UncheckedCast<Smi>(SmiSub(to84->value(), high_start97->value()));
            TNode<Smi> t405 = UncheckedCast<Smi>(SmiSub(low_end96->value(), from83->value()));
            TNode<BoolT> t406 = UncheckedCast<BoolT>(SmiLessThan(t404, t405));
            Branch(t406, label__True_129, label__False_130);
            if (label__True_129->is_used())
            {
              BIND(label__True_129);
              {
                TNode<JSTypedArray> t407 = UncheckedCast<JSTypedArray>(CallBuiltin(Builtins::kTypedArrayQuickSort, p_context, p_array, p_kind, high_start97->value(), to84->value(), p_comparefn));
                USE(t407);
                *to84 = low_end96->value();
              }
              Goto(label_if_done_label_191_242);
            }
            if (label__False_130->is_used())
            {
              BIND(label__False_130);
              {
                TNode<JSTypedArray> t408 = UncheckedCast<JSTypedArray>(CallBuiltin(Builtins::kTypedArrayQuickSort, p_context, p_array, p_kind, from83->value(), low_end96->value(), p_comparefn));
                USE(t408);
                *from83 = high_start97->value();
              }
              Goto(label_if_done_label_191_242);
            }
            BIND(label_if_done_label_191_242);
          }
        }
        Goto(label_header_185_236);
      }
      BIND(label__False_104);
    }
  }
}

TF_BUILTIN(TypedArrayQuickSort, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<JSTypedArray> p_array = UncheckedCast<JSTypedArray>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Smi> p_kind = UncheckedCast<Smi>(Parameter(Descriptor::kKind));
  USE(p_kind);
  TNode<Smi> p_from = UncheckedCast<Smi>(Parameter(Descriptor::kFrom));
  USE(p_from);
  TNode<Smi> p_to = UncheckedCast<Smi>(Parameter(Descriptor::kTo));
  USE(p_to);
  TNode<JSReceiver> p_comparefn = UncheckedCast<JSReceiver>(Parameter(Descriptor::kComparefn));
  USE(p_comparefn);
  {
    {
      Label label_try_done_192_243_impl(this);
      Label* label_try_done_192_243 = &label_try_done_192_243_impl;
      USE(label_try_done_192_243);
      Label label_Detached_131_impl(this);
      Label* label_Detached_131 = &label_Detached_131_impl;
      USE(label_Detached_131);
      Label label_try_begin_193_244_impl(this);
      Label* label_try_begin_193_244 = &label_try_begin_193_244_impl;
      USE(label_try_begin_193_244);
      Goto(label_try_begin_193_244);
      if (label_try_begin_193_244->is_used())
      {
        BIND(label_try_begin_193_244);
        {
          TypedArrayQuickSortImpl(p_context, p_array, p_kind, p_from, p_to, p_comparefn, label_Detached_131);
        }
        Goto(label_try_done_192_243);
      }
      if (label_Detached_131->is_used())
      {
        BIND(label_Detached_131);
        {
          TNode<String> t409 = StringConstant("%TypedArray%.prototype.sort");
          ThrowTypeError(p_context, MessageTemplate::kDetachedOperation, t409);
        }
      }
      BIND(label_try_done_192_243);
    }
    Return(p_array);
  }
}

TF_BUILTIN(TypedArrayPrototypeSort, TypedArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(BuiltinDescriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(BuiltinDescriptor::kArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  {
    auto t410 = [=]() {
      int32_t t412 = 0;
      TNode<IntPtrT> t413 = UncheckedCast<IntPtrT>(IntPtrConstant(t412));
      TNode<Object> t414 = UncheckedCast<Object>(GetArgumentValue(arguments, t413));
      return t414;
    };
    auto t411 = [=]() {
      return UndefinedConstant();
    };
    TVARIABLE(Object, t415194_impl);
    auto t415194 = &t415194_impl;
    USE(t415194);
    {
      Label label__True_132_impl(this);
      Label* label__True_132 = &label__True_132_impl;
      USE(label__True_132);
      Label label__False_133_impl(this);
      Label* label__False_133 = &label__False_133_impl;
      USE(label__False_133);
      Label label__done_195_245_impl(this, {t415194});
      Label* label__done_195_245 = &label__done_195_245_impl;
      USE(label__done_195_245);
      TNode<IntPtrT> t416 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
      int32_t t417 = 0;
      TNode<IntPtrT> t418 = UncheckedCast<IntPtrT>(IntPtrConstant(t417));
      TNode<BoolT> t419 = UncheckedCast<BoolT>(IntPtrGreaterThan(t416, t418));
      Branch(t419, label__True_132, label__False_133);
      BIND(label__True_132);
      *t415194 = t410();
      Goto(label__done_195_245);
      BIND(label__False_133);
      *t415194 = t411();
      Goto(label__done_195_245);
      BIND(label__done_195_245);
    }
    TVARIABLE(Object, comparefn_obj105_impl);
    auto comparefn_obj105 = &comparefn_obj105_impl;
    USE(comparefn_obj105);
    *comparefn_obj105 = t415194->value();
    {
      Label label__True_134_impl(this);
      Label* label__True_134 = &label__True_134_impl;
      USE(label__True_134);
      Label label__False_135_impl(this, {});
      Label* label__False_135 = &label__False_135_impl;
      USE(label__False_135);
      Label label__True_136_impl(this);
      Label* label__True_136 = &label__True_136_impl;
      USE(label__True_136);
      TNode<BoolT> t420 = UncheckedCast<BoolT>(WordNotEqual(comparefn_obj105->value(), UndefinedConstant()));
      GotoIfNot(t420, label__False_135);
      TNode<BoolT> t421 = UncheckedCast<BoolT>(TaggedIsCallable(comparefn_obj105->value()));
      USE(t421);
      TNode<BoolT> t422 = UncheckedCast<BoolT>(Word32BinaryNot(t421));
      Branch(t422, label__True_134, label__False_135);
      if (label__True_134->is_used())
      {
        BIND(label__True_134);
        {
          ThrowTypeError(p_context, MessageTemplate::kBadSortComparisonFunction, comparefn_obj105->value());
        }
      }
      BIND(label__False_135);
    }
    TVARIABLE(Object, obj106_impl);
    auto obj106 = &obj106_impl;
    USE(obj106);
    *obj106 = p_receiver;
    TNode<JSTypedArray> t423 = UncheckedCast<JSTypedArray>(ValidateTypedArray(p_context, obj106->value(), "%TypedArray%.prototype.sort"));
    USE(t423);
    TVARIABLE(JSTypedArray, array107_impl);
    auto array107 = &array107_impl;
    USE(array107);
    *array107 = t423;
    {
      Label label__True_137_impl(this);
      Label* label__True_137 = &label__True_137_impl;
      USE(label__True_137);
      Label label__False_138_impl(this, {});
      Label* label__False_138 = &label__False_138_impl;
      USE(label__False_138);
      TNode<BoolT> t424 = UncheckedCast<BoolT>(WordEqual(comparefn_obj105->value(), UndefinedConstant()));
      Branch(t424, label__True_137, label__False_138);
      if (label__True_137->is_used())
      {
        BIND(label__True_137);
        {
          TNode<JSTypedArray> t425 = UncheckedCast<JSTypedArray>(CallRuntime(Runtime::kTypedArraySortFast, p_context, obj106->value()));
          USE(t425);
          arguments->PopAndReturn(t425);
        }
      }
      BIND(label__False_138);
    }
    TNode<Smi> t426 = UncheckedCast<Smi>(LoadTypedArrayLength(array107->value()));
    TVARIABLE(Smi, len108_impl);
    auto len108 = &len108_impl;
    USE(len108);
    *len108 = t426;
    {
      Label label_try_done_196_246_impl(this);
      Label* label_try_done_196_246 = &label_try_done_196_246_impl;
      USE(label_try_done_196_246);
      Label label_CastError_139_impl(this);
      Label* label_CastError_139 = &label_CastError_139_impl;
      USE(label_CastError_139);
      Label label_try_begin_197_247_impl(this);
      Label* label_try_begin_197_247 = &label_try_begin_197_247_impl;
      USE(label_try_begin_197_247);
      Goto(label_try_begin_197_247);
      if (label_try_begin_197_247->is_used())
      {
        BIND(label_try_begin_197_247);
        {
          TNode<JSReceiver> t427 = UncheckedCast<JSReceiver>(TaggedToCallable(comparefn_obj105->value(), label_CastError_139));
          TVARIABLE(JSReceiver, comparefn109_impl);
          auto comparefn109 = &comparefn109_impl;
          USE(comparefn109);
          *comparefn109 = t427;
          TNode<Int32T> t428 = UncheckedCast<Int32T>(LoadElementsKind(array107->value()));
          TNode<Smi> t429 = UncheckedCast<Smi>(SmiFromInt32(t428));
          TVARIABLE(Smi, elements_kind110_impl);
          auto elements_kind110 = &elements_kind110_impl;
          USE(elements_kind110);
          *elements_kind110 = t429;
          int32_t t430 = 0;
          TNode<Smi> t431 = UncheckedCast<Smi>(SmiConstant(t430));
          TNode<JSTypedArray> t432 = UncheckedCast<JSTypedArray>(CallBuiltin(Builtins::kTypedArrayQuickSort, p_context, array107->value(), elements_kind110->value(), t431, len108->value(), comparefn109->value()));
          USE(t432);
        }
        Goto(label_try_done_196_246);
      }
      if (label_CastError_139->is_used())
      {
        BIND(label_CastError_139);
        {
          Unreachable();
        }
      }
      BIND(label_try_done_196_246);
    }
    arguments->PopAndReturn(array107->value());
  }
}

}  // namepsace internal
}  // namespace v8

