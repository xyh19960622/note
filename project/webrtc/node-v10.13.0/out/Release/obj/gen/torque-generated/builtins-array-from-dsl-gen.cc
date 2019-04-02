#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/code-factory.h"
#include "src/elements-kind.h"
#include "src/heap/factory-inl.h"
#include "src/objects.h"
#include "builtins-array-from-dsl-gen.h"

namespace v8 {
namespace internal {

using Node = compiler::Node;

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::FastArraySplice(TNode<Context> p_context, CodeStubArguments* p_args, TNode<Object> p_o, TNode<Number> p_originalLengthNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber, Label* label_Bailout_7) {
  Node* return_default = &*SmiConstant(0);
  TVARIABLE(Object, _return7_impl);
  auto _return7 = &_return7_impl;
  USE(_return7);
  *_return7 = UncheckedCast<Object>(return_default);
  Label label_macro_end_171_impl(this, {_return7});
  Label* label_macro_end_171 = &label_macro_end_171_impl;
  USE(label_macro_end_171);
  {
    TNode<Smi> t10 = UncheckedCast<Smi>(TaggedToSmi(p_originalLengthNumber, label_Bailout_7));
    TVARIABLE(Smi, originalLength8_impl);
    auto originalLength8 = &originalLength8_impl;
    USE(originalLength8);
    *originalLength8 = t10;
    TNode<Smi> t11 = UncheckedCast<Smi>(TaggedToSmi(p_actualStartNumber, label_Bailout_7));
    TVARIABLE(Smi, actualStart9_impl);
    auto actualStart9 = &actualStart9_impl;
    USE(actualStart9);
    *actualStart9 = t11;
    TNode<Smi> t12 = UncheckedCast<Smi>(TaggedToSmi(p_actualDeleteCountNumber, label_Bailout_7));
    TVARIABLE(Smi, actualDeleteCount10_impl);
    auto actualDeleteCount10 = &actualDeleteCount10_impl;
    USE(actualDeleteCount10);
    *actualDeleteCount10 = t12;
    TNode<Smi> t13 = UncheckedCast<Smi>(SmiSub(p_insertCount, actualDeleteCount10->value()));
    TVARIABLE(Smi, lengthDelta11_impl);
    auto lengthDelta11 = &lengthDelta11_impl;
    USE(lengthDelta11);
    *lengthDelta11 = t13;
    TNode<Smi> t14 = UncheckedCast<Smi>(SmiAdd(originalLength8->value(), lengthDelta11->value()));
    TVARIABLE(Smi, newLength12_impl);
    auto newLength12 = &newLength12_impl;
    USE(newLength12);
    *newLength12 = t14;
    TNode<JSArray> t15 = UncheckedCast<JSArray>(TaggedToJSArray(p_o, label_Bailout_7));
    TVARIABLE(JSArray, a13_impl);
    auto a13 = &a13_impl;
    USE(a13);
    *a13 = t15;
    TNode<Map> t16 = UncheckedCast<Map>(LoadMap(a13->value()));
    TVARIABLE(Map, map14_impl);
    auto map14 = &map14_impl;
    USE(map14);
    *map14 = t16;
    {
      Label label__True_8_impl(this);
      Label* label__True_8 = &label__True_8_impl;
      USE(label__True_8);
      Label label__False_9_impl(this, {});
      Label* label__False_9 = &label__False_9_impl;
      USE(label__False_9);
      TNode<BoolT> t17 = UncheckedCast<BoolT>(IsPrototypeInitialArrayPrototype(p_context, map14->value()));
      USE(t17);
      TNode<BoolT> t18 = UncheckedCast<BoolT>(Word32BinaryNot(t17));
      Branch(t18, label__True_8, label__False_9);
      if (label__True_8->is_used())
      {
        BIND(label__True_8);
        Goto(label_Bailout_7);
      }
      BIND(label__False_9);
    }
    {
      Label label__True_10_impl(this);
      Label* label__True_10 = &label__True_10_impl;
      USE(label__True_10);
      Label label__False_11_impl(this, {});
      Label* label__False_11 = &label__False_11_impl;
      USE(label__False_11);
      TNode<BoolT> t19 = UncheckedCast<BoolT>(IsNoElementsProtectorCellInvalid());
      USE(t19);
      Branch(t19, label__True_10, label__False_11);
      if (label__True_10->is_used())
      {
        BIND(label__True_10);
        Goto(label_Bailout_7);
      }
      BIND(label__False_11);
    }
    {
      Label label__True_12_impl(this);
      Label* label__True_12 = &label__True_12_impl;
      USE(label__True_12);
      Label label__False_13_impl(this, {});
      Label* label__False_13 = &label__False_13_impl;
      USE(label__False_13);
      TNode<BoolT> t20 = UncheckedCast<BoolT>(IsArraySpeciesProtectorCellInvalid());
      USE(t20);
      Branch(t20, label__True_12, label__False_13);
      if (label__True_12->is_used())
      {
        BIND(label__True_12);
        Goto(label_Bailout_7);
      }
      BIND(label__False_13);
    }
    TNode<Int32T> t21 = UncheckedCast<Int32T>(EnsureArrayPushable(map14->value(), label_Bailout_7));
    USE(t21);
    TVARIABLE(Int32T, elementsKind15_impl);
    auto elementsKind15 = &elementsKind15_impl;
    USE(elementsKind15);
    *elementsKind15 = t21;
    {
      Label label__True_14_impl(this);
      Label* label__True_14 = &label__True_14_impl;
      USE(label__True_14);
      Label label__False_15_impl(this, {});
      Label* label__False_15 = &label__False_15_impl;
      USE(label__False_15);
      TNode<BoolT> t22 = UncheckedCast<BoolT>(IsFastElementsKind(elementsKind15->value()));
      USE(t22);
      TNode<BoolT> t23 = UncheckedCast<BoolT>(Word32BinaryNot(t22));
      Branch(t23, label__True_14, label__False_15);
      if (label__True_14->is_used())
      {
        BIND(label__True_14);
        Goto(label_Bailout_7);
      }
      BIND(label__False_15);
    }
    {
      Label label__True_16_impl(this);
      Label* label__True_16 = &label__True_16_impl;
      USE(label__True_16);
      Label label__False_17_impl(this, {});
      Label* label__False_17 = &label__False_17_impl;
      USE(label__False_17);
      TNode<BoolT> t24 = UncheckedCast<BoolT>(IsFastSmiOrTaggedElementsKind(elementsKind15->value()));
      USE(t24);
      TNode<BoolT> t25 = UncheckedCast<BoolT>(Word32BinaryNot(t24));
      Branch(t25, label__True_16, label__False_17);
      if (label__True_16->is_used())
      {
        BIND(label__True_16);
        Goto(label_Bailout_7);
      }
      BIND(label__False_17);
    }
    {
      Label label__True_18_impl(this);
      Label* label__True_18 = &label__True_18_impl;
      USE(label__True_18);
      Label label__False_19_impl(this, {});
      Label* label__False_19 = &label__False_19_impl;
      USE(label__False_19);
      TNode<BoolT> t26 = UncheckedCast<BoolT>(IsFastSmiElementsKind(elementsKind15->value()));
      USE(t26);
      Branch(t26, label__True_18, label__False_19);
      if (label__True_18->is_used())
      {
        BIND(label__True_18);
        {
          int32_t t27 = 2;
          TNode<IntPtrT> t28 = UncheckedCast<IntPtrT>(GetArgumentsLength(p_args));
          Label label_body_125_172_impl(this);
          Label* label_body_125_172 = &label_body_125_172_impl;
          USE(label_body_125_172);
          Label label_increment_126_173_impl(this);
          Label* label_increment_126_173 = &label_increment_126_173_impl;
          USE(label_increment_126_173);
          Label label_exit_127_174_impl(this);
          Label* label_exit_127_174 = &label_exit_127_174_impl;
          USE(label_exit_127_174);
          TVARIABLE(IntPtrT, _for_index_t29128_impl);
          auto _for_index_t29128 = &_for_index_t29128_impl;
          USE(_for_index_t29128);
          TNode<IntPtrT> t30 = UncheckedCast<IntPtrT>(IntPtrConstant(t27));
          *_for_index_t29128 = t30;
          Label label_header_129_175_impl(this, {_for_index_t29128});
          Label* label_header_129_175 = &label_header_129_175_impl;
          USE(label_header_129_175);
          Goto(label_header_129_175);
          BIND(label_header_129_175);
          TNode<BoolT> t31 = UncheckedCast<BoolT>(IntPtrLessThan(_for_index_t29128->value(), t28));
          Branch(t31, label_body_125_172, label_exit_127_174);
          BIND(label_body_125_172);
          TNode<Object> t32 = UncheckedCast<Object>(GetArgumentValue(p_args, _for_index_t29128->value()));
          TVARIABLE(Object, e16_impl);
          auto e16 = &e16_impl;
          USE(e16);
          *e16 = t32;
          {
            {
              Label label__True_20_impl(this);
              Label* label__True_20 = &label__True_20_impl;
              USE(label__True_20);
              Label label__False_21_impl(this, {});
              Label* label__False_21 = &label__False_21_impl;
              USE(label__False_21);
              TNode<BoolT> t33 = UncheckedCast<BoolT>(TaggedIsNotSmi(e16->value()));
              USE(t33);
              Branch(t33, label__True_20, label__False_21);
              if (label__True_20->is_used())
              {
                BIND(label__True_20);
                Goto(label_Bailout_7);
              }
              BIND(label__False_21);
            }
          }
          Goto(label_increment_126_173);
          BIND(label_increment_126_173);
          TNode<IntPtrT> t34 = UncheckedCast<IntPtrT>(IntPtrConstant(1));
          TNode<IntPtrT> t35 = UncheckedCast<IntPtrT>(IntPtrAdd(_for_index_t29128->value(), t34));
          *_for_index_t29128 = t35;
          Goto(label_header_129_175);
          BIND(label_exit_127_174);
        }
        Goto(label__False_19);
      }
      BIND(label__False_19);
    }
    TNode<Number> t36 = UncheckedCast<Number>(LoadJSArrayLength(a13->value()));
    TNode<Smi> t37 = UncheckedCast<Smi>(TaggedToSmi(t36, label_Bailout_7));
    TVARIABLE(Smi, length17_impl);
    auto length17 = &length17_impl;
    USE(length17);
    *length17 = t37;
    {
      Label label__True_22_impl(this);
      Label* label__True_22 = &label__True_22_impl;
      USE(label__True_22);
      Label label__False_23_impl(this, {});
      Label* label__False_23 = &label__False_23_impl;
      USE(label__False_23);
      TNode<BoolT> t38 = UncheckedCast<BoolT>(SmiNotEqual(originalLength8->value(), length17->value()));
      Branch(t38, label__True_22, label__False_23);
      if (label__True_22->is_used())
      {
        BIND(label__True_22);
        Goto(label_Bailout_7);
      }
      BIND(label__False_23);
    }
    TNode<JSArray> t39 = UncheckedCast<JSArray>(CallBuiltin(Builtins::kExtractFastJSArray, p_context, a13->value(), actualStart9->value(), actualDeleteCount10->value()));
    USE(t39);
    TVARIABLE(JSArray, deletedResult18_impl);
    auto deletedResult18 = &deletedResult18_impl;
    USE(deletedResult18);
    *deletedResult18 = t39;
    {
      Label label__True_24_impl(this);
      Label* label__True_24 = &label__True_24_impl;
      USE(label__True_24);
      Label label__False_25_impl(this, {_return7});
      Label* label__False_25 = &label__False_25_impl;
      USE(label__False_25);
      int32_t t40 = 0;
      TNode<Smi> t41 = UncheckedCast<Smi>(SmiConstant(t40));
      TNode<BoolT> t42 = UncheckedCast<BoolT>(SmiEqual(newLength12->value(), t41));
      Branch(t42, label__True_24, label__False_25);
      if (label__True_24->is_used())
      {
        BIND(label__True_24);
        {
          StoreElements(a13->value(), UncheckedCast<FixedArrayBase>(LoadRoot(Heap::kEmptyFixedArrayRootIndex)));
          int32_t t43 = 0;
          TNode<Smi> t44 = UncheckedCast<Smi>(SmiConstant(t43));
          StoreJSArrayLength(a13->value(), t44);
          *_return7 = deletedResult18->value();
          Goto(label_macro_end_171);
        }
      }
      BIND(label__False_25);
    }
    TNode<FixedArrayBase> t45 = UncheckedCast<FixedArrayBase>(LoadElements(a13->value()));
    TNode<FixedArray> t46 = UncheckedCast<FixedArray>(ConvertFixedArrayBaseToFixedArray(t45, label_Bailout_7));
    TVARIABLE(FixedArray, elements19_impl);
    auto elements19 = &elements19_impl;
    USE(elements19);
    *elements19 = t46;
    TNode<Map> t47 = UncheckedCast<Map>(LoadMap(elements19->value()));
    TVARIABLE(Map, elementsMap20_impl);
    auto elementsMap20 = &elementsMap20_impl;
    USE(elementsMap20);
    *elementsMap20 = t47;
    TVARIABLE(FixedArray, newElements21_impl);
    auto newElements21 = &newElements21_impl;
    USE(newElements21);
    *newElements21 = elements19->value();
    {
      Label label__True_26_impl(this);
      Label* label__True_26 = &label__True_26_impl;
      USE(label__True_26);
      Label label__False_27_impl(this, {newElements21});
      Label* label__False_27 = &label__False_27_impl;
      USE(label__False_27);
      Label label__False_28_impl(this);
      Label* label__False_28 = &label__False_28_impl;
      USE(label__False_28);
      TNode<BoolT> t48 = UncheckedCast<BoolT>(WordEqual(elementsMap20->value(), LoadRoot(Heap::kFixedCOWArrayMapRootIndex)));
      GotoIf(t48, label__True_26);
      int32_t t49 = 0;
      TNode<Smi> t50 = UncheckedCast<Smi>(SmiConstant(t49));
      TNode<BoolT> t51 = UncheckedCast<BoolT>(SmiGreaterThan(lengthDelta11->value(), t50));
      Branch(t51, label__True_26, label__False_27);
      if (label__True_26->is_used())
      {
        BIND(label__True_26);
        {
          int32_t t52 = 0;
          TNode<Smi> t53 = UncheckedCast<Smi>(SmiConstant(t52));
          TNode<FixedArray> t54 = UncheckedCast<FixedArray>(ExtractFixedArray(elements19->value(), t53, actualStart9->value(), newLength12->value(), ExtractFixedArrayFlag::kAllFixedArrays));
          USE(t54);
          *newElements21 = t54;
          StoreMap(newElements21->value(), elementsMap20->value());
          StoreElements(a13->value(), newElements21->value());
        }
        Goto(label__False_27);
      }
      BIND(label__False_27);
    }
    TVARIABLE(Smi, k22_impl);
    auto k22 = &k22_impl;
    USE(k22);
    *k22 = actualStart9->value();
    {
      Label label__True_29_impl(this);
      Label* label__True_29 = &label__True_29_impl;
      USE(label__True_29);
      Label label__False_30_impl(this, {k22});
      Label* label__False_30 = &label__False_30_impl;
      USE(label__False_30);
      int32_t t55 = 0;
      TNode<Smi> t56 = UncheckedCast<Smi>(SmiConstant(t55));
      TNode<BoolT> t57 = UncheckedCast<BoolT>(SmiGreaterThan(p_insertCount, t56));
      Branch(t57, label__True_29, label__False_30);
      if (label__True_29->is_used())
      {
        BIND(label__True_29);
        {
          int32_t t58 = 2;
          TNode<IntPtrT> t59 = UncheckedCast<IntPtrT>(GetArgumentsLength(p_args));
          Label label_body_130_176_impl(this);
          Label* label_body_130_176 = &label_body_130_176_impl;
          USE(label_body_130_176);
          Label label_increment_131_177_impl(this);
          Label* label_increment_131_177 = &label_increment_131_177_impl;
          USE(label_increment_131_177);
          Label label_exit_132_178_impl(this);
          Label* label_exit_132_178 = &label_exit_132_178_impl;
          USE(label_exit_132_178);
          TVARIABLE(IntPtrT, _for_index_t60133_impl);
          auto _for_index_t60133 = &_for_index_t60133_impl;
          USE(_for_index_t60133);
          TNode<IntPtrT> t61 = UncheckedCast<IntPtrT>(IntPtrConstant(t58));
          *_for_index_t60133 = t61;
          Label label_header_134_179_impl(this, {_for_index_t60133, k22});
          Label* label_header_134_179 = &label_header_134_179_impl;
          USE(label_header_134_179);
          Goto(label_header_134_179);
          BIND(label_header_134_179);
          TNode<BoolT> t62 = UncheckedCast<BoolT>(IntPtrLessThan(_for_index_t60133->value(), t59));
          Branch(t62, label_body_130_176, label_exit_132_178);
          BIND(label_body_130_176);
          TNode<Object> t63 = UncheckedCast<Object>(GetArgumentValue(p_args, _for_index_t60133->value()));
          TVARIABLE(Object, e23_impl);
          auto e23 = &e23_impl;
          USE(e23);
          *e23 = t63;
          {
            TNode<Smi> t64 = k22->value();
            USE(t64);
            TNode<Smi> t65 = UncheckedCast<Smi>(SmiConstant(1));
            TNode<Smi> t66 = UncheckedCast<Smi>(SmiAdd(k22->value(), t65));
            *k22 = t66;
            StoreFixedArrayElementSmi(newElements21->value(), t64, e23->value());
          }
          Goto(label_increment_131_177);
          BIND(label_increment_131_177);
          TNode<IntPtrT> t67 = UncheckedCast<IntPtrT>(IntPtrConstant(1));
          TNode<IntPtrT> t68 = UncheckedCast<IntPtrT>(IntPtrAdd(_for_index_t60133->value(), t67));
          *_for_index_t60133 = t68;
          Goto(label_header_134_179);
          BIND(label_exit_132_178);
        }
        Goto(label__False_30);
      }
      BIND(label__False_30);
    }
    TNode<Smi> t69 = UncheckedCast<Smi>(SmiSub(length17->value(), actualStart9->value()));
    TNode<Smi> t70 = UncheckedCast<Smi>(SmiSub(t69, actualDeleteCount10->value()));
    TVARIABLE(Smi, count24_impl);
    auto count24 = &count24_impl;
    USE(count24);
    *count24 = t70;
    {
      Label label__True_31_impl(this);
      Label* label__True_31 = &label__True_31_impl;
      USE(label__True_31);
      Label label__False_32_impl(this);
      Label* label__False_32 = &label__False_32_impl;
      USE(label__False_32);
      Label label_header_135_180_impl(this, {k22, count24});
      Label* label_header_135_180 = &label_header_135_180_impl;
      USE(label_header_135_180);
      Goto(label_header_135_180);
      BIND(label_header_135_180);
      int32_t t71 = 0;
      TNode<Smi> t72 = UncheckedCast<Smi>(SmiConstant(t71));
      TNode<BoolT> t73 = UncheckedCast<BoolT>(SmiGreaterThan(count24->value(), t72));
      Branch(t73, label__True_31, label__False_32);
      if (label__True_31->is_used())
      {
        BIND(label__True_31);
        {
          TNode<Smi> t74 = UncheckedCast<Smi>(SmiSub(k22->value(), lengthDelta11->value()));
          TNode<Object> t75 = UncheckedCast<Object>(LoadFixedArrayElement(elements19->value(), t74));
          TVARIABLE(Object, e25_impl);
          auto e25 = &e25_impl;
          USE(e25);
          *e25 = t75;
          TNode<Smi> t76 = k22->value();
          USE(t76);
          TNode<Smi> t77 = UncheckedCast<Smi>(SmiConstant(1));
          TNode<Smi> t78 = UncheckedCast<Smi>(SmiAdd(k22->value(), t77));
          *k22 = t78;
          StoreFixedArrayElementSmi(newElements21->value(), t76, e25->value());
          TNode<Smi> t79 = count24->value();
          USE(t79);
          TNode<Smi> t80 = UncheckedCast<Smi>(SmiConstant(1));
          TNode<Smi> t81 = UncheckedCast<Smi>(SmiSub(count24->value(), t80));
          *count24 = t81;
        }
        Goto(label_header_135_180);
      }
      BIND(label__False_32);
    }
    {
      Label label__True_33_impl(this);
      Label* label__True_33 = &label__True_33_impl;
      USE(label__True_33);
      Label label__False_34_impl(this, {k22});
      Label* label__False_34 = &label__False_34_impl;
      USE(label__False_34);
      TNode<BoolT> t82 = UncheckedCast<BoolT>(WordEqual(elements19->value(), newElements21->value()));
      Branch(t82, label__True_33, label__False_34);
      if (label__True_33->is_used())
      {
        BIND(label__True_33);
        {
          TNode<Smi> t83 = UncheckedCast<Smi>(LoadFixedArrayBaseLength(elements19->value()));
          TVARIABLE(Smi, limit26_impl);
          auto limit26 = &limit26_impl;
          USE(limit26);
          *limit26 = t83;
          {
            Label label__True_35_impl(this);
            Label* label__True_35 = &label__True_35_impl;
            USE(label__True_35);
            Label label__False_36_impl(this);
            Label* label__False_36 = &label__False_36_impl;
            USE(label__False_36);
            Label label_header_136_181_impl(this, {k22});
            Label* label_header_136_181 = &label_header_136_181_impl;
            USE(label_header_136_181);
            Goto(label_header_136_181);
            BIND(label_header_136_181);
            TNode<BoolT> t84 = UncheckedCast<BoolT>(SmiLessThan(k22->value(), limit26->value()));
            Branch(t84, label__True_35, label__False_36);
            if (label__True_35->is_used())
            {
              BIND(label__True_35);
              {
                TNode<Smi> t85 = k22->value();
                USE(t85);
                TNode<Smi> t86 = UncheckedCast<Smi>(SmiConstant(1));
                TNode<Smi> t87 = UncheckedCast<Smi>(SmiAdd(k22->value(), t86));
                *k22 = t87;
                StoreFixedArrayElementSmi(newElements21->value(), t85, TheHoleConstant());
              }
              Goto(label_header_136_181);
            }
            BIND(label__False_36);
          }
        }
        Goto(label__False_34);
      }
      BIND(label__False_34);
    }
    StoreJSArrayLength(a13->value(), newLength12->value());
    *_return7 = deletedResult18->value();
    Goto(label_macro_end_171);
  }
  BIND(label_macro_end_171);
  return _return7->value();
}

TF_BUILTIN(ArraySpliceTorque, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(BuiltinDescriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(BuiltinDescriptor::kArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  {
    TNode<Object> t88 = UncheckedCast<Object>(CallBuiltin(Builtins::kToObject, p_context, p_receiver));
    USE(t88);
    TVARIABLE(Object, o27_impl);
    auto o27 = &o27_impl;
    USE(o27);
    *o27 = t88;
    TNode<String> t89 = StringConstant("length");
    TNode<Object> t90 = UncheckedCast<Object>(GetProperty(p_context, o27->value(), t89));
    USE(t90);
    TNode<Number> t91 = UncheckedCast<Number>(ToLength_Inline(p_context, t90));
    USE(t91);
    TVARIABLE(Number, len28_impl);
    auto len28 = &len28_impl;
    USE(len28);
    *len28 = t91;
    int32_t t92 = 0;
    TNode<IntPtrT> t93 = UncheckedCast<IntPtrT>(IntPtrConstant(t92));
    TNode<Object> t94 = UncheckedCast<Object>(GetArgumentValue(arguments, t93));
    TVARIABLE(Object, start29_impl);
    auto start29 = &start29_impl;
    USE(start29);
    *start29 = t94;
    TNode<Number> t95 = UncheckedCast<Number>(ToInteger_Inline(p_context, start29->value()));
    USE(t95);
    TVARIABLE(Number, relativeStart30_impl);
    auto relativeStart30 = &relativeStart30_impl;
    USE(relativeStart30);
    *relativeStart30 = t95;
    auto t96 = [=]() {
      TNode<Number> t98 = UncheckedCast<Number>(NumberAdd(len28->value(), relativeStart30->value()));
      int32_t t99 = 0;
      TNode<Smi> t100 = UncheckedCast<Smi>(SmiConstant(t99));
      TNode<Number> t101 = UncheckedCast<Number>(NumberMax(t98, t100));
      return t101;
    };
    auto t97 = [=]() {
      TNode<Number> t102 = UncheckedCast<Number>(NumberMin(relativeStart30->value(), len28->value()));
      return t102;
    };
    TVARIABLE(Number, t103137_impl);
    auto t103137 = &t103137_impl;
    USE(t103137);
    {
      Label label__True_37_impl(this);
      Label* label__True_37 = &label__True_37_impl;
      USE(label__True_37);
      Label label__False_38_impl(this);
      Label* label__False_38 = &label__False_38_impl;
      USE(label__False_38);
      Label label__done_138_182_impl(this, {t103137});
      Label* label__done_138_182 = &label__done_138_182_impl;
      USE(label__done_138_182);
      int32_t t104 = 0;
      TNode<Smi> t105 = UncheckedCast<Smi>(SmiConstant(t104));
      BranchIfNumberLessThan(relativeStart30->value(), t105, label__True_37, label__False_38);
      BIND(label__True_37);
      *t103137 = t96();
      Goto(label__done_138_182);
      BIND(label__False_38);
      *t103137 = t97();
      Goto(label__done_138_182);
      BIND(label__done_138_182);
    }
    TVARIABLE(Number, actualStart31_impl);
    auto actualStart31 = &actualStart31_impl;
    USE(actualStart31);
    *actualStart31 = t103137->value();
    TVARIABLE(Smi, insertCount32_impl);
    auto insertCount32 = &insertCount32_impl;
    USE(insertCount32);
    TVARIABLE(Number, actualDeleteCount33_impl);
    auto actualDeleteCount33 = &actualDeleteCount33_impl;
    USE(actualDeleteCount33);
    {
      Label label__True_39_impl(this);
      Label* label__True_39 = &label__True_39_impl;
      USE(label__True_39);
      Label label__False_40_impl(this);
      Label* label__False_40 = &label__False_40_impl;
      USE(label__False_40);
      Label label_if_done_label_139_183_impl(this, {insertCount32, actualDeleteCount33});
      Label* label_if_done_label_139_183 = &label_if_done_label_139_183_impl;
      USE(label_if_done_label_139_183);
      TNode<IntPtrT> t106 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
      int32_t t107 = 0;
      TNode<IntPtrT> t108 = UncheckedCast<IntPtrT>(IntPtrConstant(t107));
      TNode<BoolT> t109 = UncheckedCast<BoolT>(WordEqual(t106, t108));
      Branch(t109, label__True_39, label__False_40);
      if (label__True_39->is_used())
      {
        BIND(label__True_39);
        {
          int32_t t110 = 0;
          TNode<Smi> t111 = UncheckedCast<Smi>(SmiConstant(t110));
          *insertCount32 = t111;
          int32_t t112 = 0;
          TNode<Smi> t113 = UncheckedCast<Smi>(SmiConstant(t112));
          *actualDeleteCount33 = t113;
        }
        Goto(label_if_done_label_139_183);
      }
      if (label__False_40->is_used())
      {
        BIND(label__False_40);
        {
          Label label__True_41_impl(this);
          Label* label__True_41 = &label__True_41_impl;
          USE(label__True_41);
          Label label__False_42_impl(this);
          Label* label__False_42 = &label__False_42_impl;
          USE(label__False_42);
          Label label_if_done_label_140_184_impl(this, {insertCount32, actualDeleteCount33});
          Label* label_if_done_label_140_184 = &label_if_done_label_140_184_impl;
          USE(label_if_done_label_140_184);
          TNode<IntPtrT> t114 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
          int32_t t115 = 1;
          TNode<IntPtrT> t116 = UncheckedCast<IntPtrT>(IntPtrConstant(t115));
          TNode<BoolT> t117 = UncheckedCast<BoolT>(WordEqual(t114, t116));
          Branch(t117, label__True_41, label__False_42);
          if (label__True_41->is_used())
          {
            BIND(label__True_41);
            {
              int32_t t118 = 0;
              TNode<Smi> t119 = UncheckedCast<Smi>(SmiConstant(t118));
              *insertCount32 = t119;
              TNode<Number> t120 = UncheckedCast<Number>(NumberSub(len28->value(), actualStart31->value()));
              *actualDeleteCount33 = t120;
            }
            Goto(label_if_done_label_140_184);
          }
          if (label__False_42->is_used())
          {
            BIND(label__False_42);
            {
              TNode<IntPtrT> t121 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
              TNode<Smi> t122 = UncheckedCast<Smi>(SmiTag(t121));
              int32_t t123 = 2;
              TNode<Smi> t124 = UncheckedCast<Smi>(SmiConstant(t123));
              TNode<Smi> t125 = UncheckedCast<Smi>(SmiSub(t122, t124));
              *insertCount32 = t125;
              int32_t t126 = 1;
              TNode<IntPtrT> t127 = UncheckedCast<IntPtrT>(IntPtrConstant(t126));
              TNode<Object> t128 = UncheckedCast<Object>(GetArgumentValue(arguments, t127));
              TVARIABLE(Object, deleteCount34_impl);
              auto deleteCount34 = &deleteCount34_impl;
              USE(deleteCount34);
              *deleteCount34 = t128;
              TNode<Number> t129 = UncheckedCast<Number>(ToInteger_Inline(p_context, deleteCount34->value()));
              USE(t129);
              TVARIABLE(Number, dc35_impl);
              auto dc35 = &dc35_impl;
              USE(dc35);
              *dc35 = t129;
              int32_t t130 = 0;
              TNode<Smi> t131 = UncheckedCast<Smi>(SmiConstant(t130));
              TNode<Number> t132 = UncheckedCast<Number>(NumberMax(dc35->value(), t131));
              TNode<Number> t133 = UncheckedCast<Number>(NumberSub(len28->value(), actualStart31->value()));
              TNode<Number> t134 = UncheckedCast<Number>(NumberMin(t132, t133));
              *actualDeleteCount33 = t134;
            }
            Goto(label_if_done_label_140_184);
          }
          BIND(label_if_done_label_140_184);
        }
        Goto(label_if_done_label_139_183);
      }
      BIND(label_if_done_label_139_183);
    }
    {
      Label label__True_43_impl(this);
      Label* label__True_43 = &label__True_43_impl;
      USE(label__True_43);
      Label label__False_44_impl(this, {});
      Label* label__False_44 = &label__False_44_impl;
      USE(label__False_44);
      TNode<Number> t135 = UncheckedCast<Number>(NumberAdd(len28->value(), insertCount32->value()));
      TNode<Number> t136 = UncheckedCast<Number>(NumberSub(t135, actualDeleteCount33->value()));
      TNode<Number> t137 = UncheckedCast<Number>(AllocateHeapNumberWithValue(kMaxSafeInteger));
      BranchIfNumberGreaterThan(t136, t137, label__True_43, label__False_44);
      if (label__True_43->is_used())
      {
        BIND(label__True_43);
        {
          ThrowRangeError(p_context, MessageTemplate::kInvalidArrayLength);
        }
      }
      BIND(label__False_44);
    }
    {
      Label label_try_done_141_185_impl(this);
      Label* label_try_done_141_185 = &label_try_done_141_185_impl;
      USE(label_try_done_141_185);
      Label label_Bailout_45_impl(this);
      Label* label_Bailout_45 = &label_Bailout_45_impl;
      USE(label_Bailout_45);
      Label label_try_begin_142_186_impl(this);
      Label* label_try_begin_142_186 = &label_try_begin_142_186_impl;
      USE(label_try_begin_142_186);
      Goto(label_try_begin_142_186);
      if (label_try_begin_142_186->is_used())
      {
        BIND(label_try_begin_142_186);
        {
          TNode<Object> t138 = UncheckedCast<Object>(FastArraySplice(p_context, arguments, o27->value(), len28->value(), actualStart31->value(), insertCount32->value(), actualDeleteCount33->value(), label_Bailout_45));
          USE(t138);
          arguments->PopAndReturn(t138);
        }
      }
      if (label_Bailout_45->is_used())
      {
        BIND(label_Bailout_45);
        {
        }
        Goto(label_try_done_141_185);
      }
      BIND(label_try_done_141_185);
    }
    TNode<Object> t139 = UncheckedCast<Object>(ArraySpeciesCreate(p_context, o27->value(), actualDeleteCount33->value()));
    USE(t139);
    TVARIABLE(Object, a36_impl);
    auto a36 = &a36_impl;
    USE(a36);
    *a36 = t139;
    int32_t t140 = 0;
    TVARIABLE(Number, k37_impl);
    auto k37 = &k37_impl;
    USE(k37);
    TNode<Smi> t141 = UncheckedCast<Smi>(SmiConstant(t140));
    *k37 = t141;
    {
      Label label__True_46_impl(this);
      Label* label__True_46 = &label__True_46_impl;
      USE(label__True_46);
      Label label__False_47_impl(this);
      Label* label__False_47 = &label__False_47_impl;
      USE(label__False_47);
      Label label_header_143_187_impl(this, {k37});
      Label* label_header_143_187 = &label_header_143_187_impl;
      USE(label_header_143_187);
      Goto(label_header_143_187);
      BIND(label_header_143_187);
      BranchIfNumberLessThan(k37->value(), actualDeleteCount33->value(), label__True_46, label__False_47);
      if (label__True_46->is_used())
      {
        BIND(label__True_46);
        {
          TNode<Number> t142 = UncheckedCast<Number>(NumberAdd(actualStart31->value(), k37->value()));
          TNode<String> t143 = UncheckedCast<String>(ToString_Inline(p_context, t142));
          USE(t143);
          TVARIABLE(String, from38_impl);
          auto from38 = &from38_impl;
          USE(from38);
          *from38 = t143;
          TNode<Oddball> t144 = UncheckedCast<Oddball>(HasPropertyObject(o27->value(), from38->value(), p_context, kHasProperty));
          USE(t144);
          TVARIABLE(Oddball, fromPresent39_impl);
          auto fromPresent39 = &fromPresent39_impl;
          USE(fromPresent39);
          *fromPresent39 = t144;
          {
            Label label__True_48_impl(this);
            Label* label__True_48 = &label__True_48_impl;
            USE(label__True_48);
            Label label__False_49_impl(this, {});
            Label* label__False_49 = &label__False_49_impl;
            USE(label__False_49);
            TNode<BoolT> t145 = UncheckedCast<BoolT>(WordEqual(fromPresent39->value(), TrueConstant()));
            Branch(t145, label__True_48, label__False_49);
            if (label__True_48->is_used())
            {
              BIND(label__True_48);
              {
                TNode<Object> t146 = UncheckedCast<Object>(GetProperty(p_context, o27->value(), from38->value()));
                USE(t146);
                TVARIABLE(Object, fromValue40_impl);
                auto fromValue40 = &fromValue40_impl;
                USE(fromValue40);
                *fromValue40 = t146;
                TNode<String> t147 = UncheckedCast<String>(ToString_Inline(p_context, k37->value()));
                USE(t147);
                CallRuntime(Runtime::kCreateDataProperty, p_context, a36->value(), t147, fromValue40->value());
              }
              Goto(label__False_49);
            }
            BIND(label__False_49);
          }
          int32_t t148 = 1;
          TNode<Smi> t149 = UncheckedCast<Smi>(SmiConstant(t148));
          TNode<Number> t150 = UncheckedCast<Number>(NumberAdd(k37->value(), t149));
          *k37 = t150;
        }
        Goto(label_header_143_187);
      }
      BIND(label__False_47);
    }
    TNode<String> t151 = StringConstant("length");
    TNode<Smi> t152 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
    CallRuntime(Runtime::kSetProperty, p_context, a36->value(), t151, actualDeleteCount33->value(), t152);
    TVARIABLE(Number, itemCount41_impl);
    auto itemCount41 = &itemCount41_impl;
    USE(itemCount41);
    *itemCount41 = insertCount32->value();
    {
      Label label__True_50_impl(this);
      Label* label__True_50 = &label__True_50_impl;
      USE(label__True_50);
      Label label__False_51_impl(this);
      Label* label__False_51 = &label__False_51_impl;
      USE(label__False_51);
      Label label_if_done_label_144_188_impl(this, {});
      Label* label_if_done_label_144_188 = &label_if_done_label_144_188_impl;
      USE(label_if_done_label_144_188);
      BranchIfNumberLessThan(itemCount41->value(), actualDeleteCount33->value(), label__True_50, label__False_51);
      if (label__True_50->is_used())
      {
        BIND(label__True_50);
        {
          TVARIABLE(Number, k42_impl);
          auto k42 = &k42_impl;
          USE(k42);
          *k42 = actualStart31->value();
          {
            Label label__True_52_impl(this);
            Label* label__True_52 = &label__True_52_impl;
            USE(label__True_52);
            Label label__False_53_impl(this);
            Label* label__False_53 = &label__False_53_impl;
            USE(label__False_53);
            Label label_header_145_189_impl(this, {k42});
            Label* label_header_145_189 = &label_header_145_189_impl;
            USE(label_header_145_189);
            Goto(label_header_145_189);
            BIND(label_header_145_189);
            TNode<Number> t153 = UncheckedCast<Number>(NumberSub(len28->value(), actualDeleteCount33->value()));
            BranchIfNumberLessThan(k42->value(), t153, label__True_52, label__False_53);
            if (label__True_52->is_used())
            {
              BIND(label__True_52);
              {
                TNode<Number> t154 = UncheckedCast<Number>(NumberAdd(k42->value(), actualDeleteCount33->value()));
                TNode<String> t155 = UncheckedCast<String>(ToString_Inline(p_context, t154));
                USE(t155);
                TVARIABLE(String, from43_impl);
                auto from43 = &from43_impl;
                USE(from43);
                *from43 = t155;
                TNode<Number> t156 = UncheckedCast<Number>(NumberAdd(k42->value(), itemCount41->value()));
                TNode<String> t157 = UncheckedCast<String>(ToString_Inline(p_context, t156));
                USE(t157);
                TVARIABLE(String, to44_impl);
                auto to44 = &to44_impl;
                USE(to44);
                *to44 = t157;
                TNode<Oddball> t158 = UncheckedCast<Oddball>(HasPropertyObject(o27->value(), from43->value(), p_context, kHasProperty));
                USE(t158);
                TVARIABLE(Oddball, fromPresent45_impl);
                auto fromPresent45 = &fromPresent45_impl;
                USE(fromPresent45);
                *fromPresent45 = t158;
                {
                  Label label__True_54_impl(this);
                  Label* label__True_54 = &label__True_54_impl;
                  USE(label__True_54);
                  Label label__False_55_impl(this);
                  Label* label__False_55 = &label__False_55_impl;
                  USE(label__False_55);
                  Label label_if_done_label_146_190_impl(this, {});
                  Label* label_if_done_label_146_190 = &label_if_done_label_146_190_impl;
                  USE(label_if_done_label_146_190);
                  TNode<BoolT> t159 = UncheckedCast<BoolT>(WordEqual(fromPresent45->value(), TrueConstant()));
                  Branch(t159, label__True_54, label__False_55);
                  if (label__True_54->is_used())
                  {
                    BIND(label__True_54);
                    {
                      TNode<Object> t160 = UncheckedCast<Object>(GetProperty(p_context, o27->value(), from43->value()));
                      USE(t160);
                      TVARIABLE(Object, fromValue46_impl);
                      auto fromValue46 = &fromValue46_impl;
                      USE(fromValue46);
                      *fromValue46 = t160;
                      TNode<Smi> t161 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
                      CallRuntime(Runtime::kSetProperty, p_context, o27->value(), to44->value(), fromValue46->value(), t161);
                    }
                    Goto(label_if_done_label_146_190);
                  }
                  if (label__False_55->is_used())
                  {
                    BIND(label__False_55);
                    {
                      TNode<Smi> t162 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
                      CallRuntime(Runtime::kDeleteProperty, p_context, o27->value(), to44->value(), t162);
                    }
                    Goto(label_if_done_label_146_190);
                  }
                  BIND(label_if_done_label_146_190);
                }
                int32_t t163 = 1;
                TNode<Smi> t164 = UncheckedCast<Smi>(SmiConstant(t163));
                TNode<Number> t165 = UncheckedCast<Number>(NumberAdd(k42->value(), t164));
                *k42 = t165;
              }
              Goto(label_header_145_189);
            }
            BIND(label__False_53);
          }
          *k42 = len28->value();
          {
            Label label__True_56_impl(this);
            Label* label__True_56 = &label__True_56_impl;
            USE(label__True_56);
            Label label__False_57_impl(this);
            Label* label__False_57 = &label__False_57_impl;
            USE(label__False_57);
            Label label_header_147_191_impl(this, {k42});
            Label* label_header_147_191 = &label_header_147_191_impl;
            USE(label_header_147_191);
            Goto(label_header_147_191);
            BIND(label_header_147_191);
            TNode<Number> t166 = UncheckedCast<Number>(NumberSub(len28->value(), actualDeleteCount33->value()));
            TNode<Number> t167 = UncheckedCast<Number>(NumberAdd(t166, itemCount41->value()));
            BranchIfNumberGreaterThan(k42->value(), t167, label__True_56, label__False_57);
            if (label__True_56->is_used())
            {
              BIND(label__True_56);
              {
                int32_t t168 = 1;
                TNode<Smi> t169 = UncheckedCast<Smi>(SmiConstant(t168));
                TNode<Number> t170 = UncheckedCast<Number>(NumberSub(k42->value(), t169));
                TNode<String> t171 = UncheckedCast<String>(ToString_Inline(p_context, t170));
                USE(t171);
                TNode<Smi> t172 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
                CallRuntime(Runtime::kDeleteProperty, p_context, o27->value(), t171, t172);
                int32_t t173 = 1;
                TNode<Smi> t174 = UncheckedCast<Smi>(SmiConstant(t173));
                TNode<Number> t175 = UncheckedCast<Number>(NumberSub(k42->value(), t174));
                *k42 = t175;
              }
              Goto(label_header_147_191);
            }
            BIND(label__False_57);
          }
        }
        Goto(label_if_done_label_144_188);
      }
      if (label__False_51->is_used())
      {
        BIND(label__False_51);
        {
          Label label__True_58_impl(this);
          Label* label__True_58 = &label__True_58_impl;
          USE(label__True_58);
          Label label__False_59_impl(this, {});
          Label* label__False_59 = &label__False_59_impl;
          USE(label__False_59);
          BranchIfNumberGreaterThan(itemCount41->value(), actualDeleteCount33->value(), label__True_58, label__False_59);
          if (label__True_58->is_used())
          {
            BIND(label__True_58);
            {
              TNode<Number> t176 = UncheckedCast<Number>(NumberSub(len28->value(), actualDeleteCount33->value()));
              TVARIABLE(Number, k47_impl);
              auto k47 = &k47_impl;
              USE(k47);
              *k47 = t176;
              {
                Label label__True_60_impl(this);
                Label* label__True_60 = &label__True_60_impl;
                USE(label__True_60);
                Label label__False_61_impl(this);
                Label* label__False_61 = &label__False_61_impl;
                USE(label__False_61);
                Label label_header_148_192_impl(this, {k47});
                Label* label_header_148_192 = &label_header_148_192_impl;
                USE(label_header_148_192);
                Goto(label_header_148_192);
                BIND(label_header_148_192);
                BranchIfNumberGreaterThan(k47->value(), actualStart31->value(), label__True_60, label__False_61);
                if (label__True_60->is_used())
                {
                  BIND(label__True_60);
                  {
                    TNode<Number> t177 = UncheckedCast<Number>(NumberAdd(k47->value(), actualDeleteCount33->value()));
                    int32_t t178 = 1;
                    TNode<Smi> t179 = UncheckedCast<Smi>(SmiConstant(t178));
                    TNode<Number> t180 = UncheckedCast<Number>(NumberSub(t177, t179));
                    TNode<String> t181 = UncheckedCast<String>(ToString_Inline(p_context, t180));
                    USE(t181);
                    TVARIABLE(String, from48_impl);
                    auto from48 = &from48_impl;
                    USE(from48);
                    *from48 = t181;
                    TNode<Number> t182 = UncheckedCast<Number>(NumberAdd(k47->value(), itemCount41->value()));
                    int32_t t183 = 1;
                    TNode<Smi> t184 = UncheckedCast<Smi>(SmiConstant(t183));
                    TNode<Number> t185 = UncheckedCast<Number>(NumberSub(t182, t184));
                    TNode<String> t186 = UncheckedCast<String>(ToString_Inline(p_context, t185));
                    USE(t186);
                    TVARIABLE(String, to49_impl);
                    auto to49 = &to49_impl;
                    USE(to49);
                    *to49 = t186;
                    TNode<Oddball> t187 = UncheckedCast<Oddball>(HasPropertyObject(o27->value(), from48->value(), p_context, kHasProperty));
                    USE(t187);
                    TVARIABLE(Oddball, fromPresent50_impl);
                    auto fromPresent50 = &fromPresent50_impl;
                    USE(fromPresent50);
                    *fromPresent50 = t187;
                    {
                      Label label__True_62_impl(this);
                      Label* label__True_62 = &label__True_62_impl;
                      USE(label__True_62);
                      Label label__False_63_impl(this);
                      Label* label__False_63 = &label__False_63_impl;
                      USE(label__False_63);
                      Label label_if_done_label_149_193_impl(this, {});
                      Label* label_if_done_label_149_193 = &label_if_done_label_149_193_impl;
                      USE(label_if_done_label_149_193);
                      TNode<BoolT> t188 = UncheckedCast<BoolT>(WordEqual(fromPresent50->value(), TrueConstant()));
                      Branch(t188, label__True_62, label__False_63);
                      if (label__True_62->is_used())
                      {
                        BIND(label__True_62);
                        {
                          TNode<Object> t189 = UncheckedCast<Object>(GetProperty(p_context, o27->value(), from48->value()));
                          USE(t189);
                          TVARIABLE(Object, fromValue51_impl);
                          auto fromValue51 = &fromValue51_impl;
                          USE(fromValue51);
                          *fromValue51 = t189;
                          TNode<Smi> t190 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
                          CallRuntime(Runtime::kSetProperty, p_context, o27->value(), to49->value(), fromValue51->value(), t190);
                        }
                        Goto(label_if_done_label_149_193);
                      }
                      if (label__False_63->is_used())
                      {
                        BIND(label__False_63);
                        {
                          TNode<Smi> t191 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
                          CallRuntime(Runtime::kDeleteProperty, p_context, o27->value(), to49->value(), t191);
                        }
                        Goto(label_if_done_label_149_193);
                      }
                      BIND(label_if_done_label_149_193);
                    }
                    int32_t t192 = 1;
                    TNode<Smi> t193 = UncheckedCast<Smi>(SmiConstant(t192));
                    TNode<Number> t194 = UncheckedCast<Number>(NumberSub(k47->value(), t193));
                    *k47 = t194;
                  }
                  Goto(label_header_148_192);
                }
                BIND(label__False_61);
              }
            }
            Goto(label__False_59);
          }
          BIND(label__False_59);
        }
        Goto(label_if_done_label_144_188);
      }
      BIND(label_if_done_label_144_188);
    }
    *k37 = actualStart31->value();
    {
      Label label__True_64_impl(this);
      Label* label__True_64 = &label__True_64_impl;
      USE(label__True_64);
      Label label__False_65_impl(this, {k37});
      Label* label__False_65 = &label__False_65_impl;
      USE(label__False_65);
      TNode<IntPtrT> t195 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
      int32_t t196 = 2;
      TNode<IntPtrT> t197 = UncheckedCast<IntPtrT>(IntPtrConstant(t196));
      TNode<BoolT> t198 = UncheckedCast<BoolT>(IntPtrGreaterThan(t195, t197));
      Branch(t198, label__True_64, label__False_65);
      if (label__True_64->is_used())
      {
        BIND(label__True_64);
        {
          int32_t t199 = 2;
          TNode<IntPtrT> t200 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
          Label label_body_150_194_impl(this);
          Label* label_body_150_194 = &label_body_150_194_impl;
          USE(label_body_150_194);
          Label label_increment_151_195_impl(this);
          Label* label_increment_151_195 = &label_increment_151_195_impl;
          USE(label_increment_151_195);
          Label label_exit_152_196_impl(this);
          Label* label_exit_152_196 = &label_exit_152_196_impl;
          USE(label_exit_152_196);
          TVARIABLE(IntPtrT, _for_index_t201153_impl);
          auto _for_index_t201153 = &_for_index_t201153_impl;
          USE(_for_index_t201153);
          TNode<IntPtrT> t202 = UncheckedCast<IntPtrT>(IntPtrConstant(t199));
          *_for_index_t201153 = t202;
          Label label_header_154_197_impl(this, {_for_index_t201153, k37});
          Label* label_header_154_197 = &label_header_154_197_impl;
          USE(label_header_154_197);
          Goto(label_header_154_197);
          BIND(label_header_154_197);
          TNode<BoolT> t203 = UncheckedCast<BoolT>(IntPtrLessThan(_for_index_t201153->value(), t200));
          Branch(t203, label_body_150_194, label_exit_152_196);
          BIND(label_body_150_194);
          TNode<Object> t204 = UncheckedCast<Object>(GetArgumentValue(arguments, _for_index_t201153->value()));
          TVARIABLE(Object, e52_impl);
          auto e52 = &e52_impl;
          USE(e52);
          *e52 = t204;
          {
            TNode<String> t205 = UncheckedCast<String>(ToString_Inline(p_context, k37->value()));
            USE(t205);
            TNode<Smi> t206 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
            CallRuntime(Runtime::kSetProperty, p_context, o27->value(), t205, e52->value(), t206);
            int32_t t207 = 1;
            TNode<Smi> t208 = UncheckedCast<Smi>(SmiConstant(t207));
            TNode<Number> t209 = UncheckedCast<Number>(NumberAdd(k37->value(), t208));
            *k37 = t209;
          }
          Goto(label_increment_151_195);
          BIND(label_increment_151_195);
          TNode<IntPtrT> t210 = UncheckedCast<IntPtrT>(IntPtrConstant(1));
          TNode<IntPtrT> t211 = UncheckedCast<IntPtrT>(IntPtrAdd(_for_index_t201153->value(), t210));
          *_for_index_t201153 = t211;
          Goto(label_header_154_197);
          BIND(label_exit_152_196);
        }
        Goto(label__False_65);
      }
      BIND(label__False_65);
    }
    TNode<String> t212 = StringConstant("length");
    TNode<Number> t213 = UncheckedCast<Number>(NumberSub(len28->value(), actualDeleteCount33->value()));
    TNode<Number> t214 = UncheckedCast<Number>(NumberAdd(t213, itemCount41->value()));
    TNode<Smi> t215 = UncheckedCast<Smi>(LanguageModeConstant(LanguageMode::kStrict));
    CallRuntime(Runtime::kSetProperty, p_context, o27->value(), t212, t214, t215);
    arguments->PopAndReturn(a36->value());
  }
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::ArrayForEachTorqueContinuation(TNode<Context> p_context, TNode<Object> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, TNode<Number> p_initial_k) {
  Node* return_default = &*SmiConstant(0);
  TVARIABLE(Object, _return53_impl);
  auto _return53 = &_return53_impl;
  USE(_return53);
  *_return53 = UncheckedCast<Object>(return_default);
  Label label_macro_end_198_impl(this, {_return53});
  Label* label_macro_end_198 = &label_macro_end_198_impl;
  USE(label_macro_end_198);
  {
    TVARIABLE(Number, k54_impl);
    auto k54 = &k54_impl;
    USE(k54);
    *k54 = p_initial_k;
    Label label__True_66_impl(this);
    Label* label__True_66 = &label__True_66_impl;
    USE(label__True_66);
    Label label__False_67_impl(this);
    Label* label__False_67 = &label__False_67_impl;
    USE(label__False_67);
    Label label_header_155_199_impl(this, {k54});
    Label* label_header_155_199 = &label_header_155_199_impl;
    USE(label_header_155_199);
    Goto(label_header_155_199);
    BIND(label_header_155_199);
    Label label_assignment_156_200_impl(this);
    Label* label_assignment_156_200 = &label_assignment_156_200_impl;
    USE(label_assignment_156_200);
    BranchIfNumberLessThan(k54->value(), p_len, label__True_66, label__False_67);
    if (label__True_66->is_used())
    {
      BIND(label__True_66);
      {
        TNode<Oddball> t216 = UncheckedCast<Oddball>(HasPropertyObject(p_o, k54->value(), p_context, kHasProperty));
        USE(t216);
        TVARIABLE(Oddball, kPresent55_impl);
        auto kPresent55 = &kPresent55_impl;
        USE(kPresent55);
        *kPresent55 = t216;
        {
          Label label__True_68_impl(this);
          Label* label__True_68 = &label__True_68_impl;
          USE(label__True_68);
          Label label__False_69_impl(this, {});
          Label* label__False_69 = &label__False_69_impl;
          USE(label__False_69);
          TNode<BoolT> t217 = UncheckedCast<BoolT>(WordEqual(kPresent55->value(), TrueConstant()));
          Branch(t217, label__True_68, label__False_69);
          if (label__True_68->is_used())
          {
            BIND(label__True_68);
            {
              TNode<Object> t218 = UncheckedCast<Object>(GetProperty(p_context, p_o, k54->value()));
              USE(t218);
              TVARIABLE(Object, kValue56_impl);
              auto kValue56 = &kValue56_impl;
              USE(kValue56);
              *kValue56 = t218;
              TNode<Object> t219 = UncheckedCast<Object>(Call(p_context, p_callbackfn, p_thisArg, kValue56->value(), k54->value(), p_o));
              USE(t219);
            }
            Goto(label__False_69);
          }
          BIND(label__False_69);
        }
      }
      Goto(label_assignment_156_200);
    }
    {
      BIND(label_assignment_156_200);
      int32_t t220 = 1;
      TNode<Smi> t221 = UncheckedCast<Smi>(SmiConstant(t220));
      TNode<Number> t222 = UncheckedCast<Number>(NumberAdd(k54->value(), t221));
      *k54 = t222;
      Goto(label_header_155_199);
    }
    BIND(label__False_67);
    *_return53 = UndefinedConstant();
    Goto(label_macro_end_198);
  }
  BIND(label_macro_end_198);
  return _return53->value();
}

TF_BUILTIN(ArrayForEachLoopEagerDeoptContinuation, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_receiver = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_callback = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(p_callback);
  TNode<Object> p_thisArg = UncheckedCast<Object>(Parameter(Descriptor::kThisArg));
  USE(p_thisArg);
  TNode<Object> p_initialK = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(p_initialK);
  TNode<Object> p_length = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(p_length);
  {
    TNode<Object> t223 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayForEachLoopContinuation, p_context, p_receiver, p_callback, p_thisArg, UndefinedConstant(), p_receiver, p_initialK, p_length, UndefinedConstant()));
    USE(t223);
    Return(t223);
  }
}

TF_BUILTIN(ArrayForEachLoopLazyDeoptContinuation, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_receiver = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_callback = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(p_callback);
  TNode<Object> p_thisArg = UncheckedCast<Object>(Parameter(Descriptor::kThisArg));
  USE(p_thisArg);
  TNode<Object> p_initialK = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(p_initialK);
  TNode<Object> p_length = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(p_length);
  TNode<Object> p_result = UncheckedCast<Object>(Parameter(Descriptor::kResult));
  USE(p_result);
  {
    TNode<Object> t224 = UncheckedCast<Object>(CallBuiltin(Builtins::kArrayForEachLoopContinuation, p_context, p_receiver, p_callback, p_thisArg, UndefinedConstant(), p_receiver, p_initialK, p_length, UndefinedConstant()));
    USE(t224);
    Return(t224);
  }
}

TF_BUILTIN(ArrayForEachLoopContinuation, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(p_context);
  TNode<Object> p_receiver = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
  USE(p_receiver);
  TNode<Object> p_callback = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(p_callback);
  TNode<Object> p_thisArg = UncheckedCast<Object>(Parameter(Descriptor::kThisArg));
  USE(p_thisArg);
  TNode<Object> p_array = UncheckedCast<Object>(Parameter(Descriptor::kArray));
  USE(p_array);
  TNode<Object> p_object = UncheckedCast<Object>(Parameter(Descriptor::kObject));
  USE(p_object);
  TNode<Object> p_initialK = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(p_initialK);
  TNode<Object> p_length = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(p_length);
  TNode<Object> p_to = UncheckedCast<Object>(Parameter(Descriptor::kTo));
  USE(p_to);
  {
    {
      Label label_try_done_157_201_impl(this);
      Label* label_try_done_157_201 = &label_try_done_157_201_impl;
      USE(label_try_done_157_201);
      Label label_Unexpected_70_impl(this);
      Label* label_Unexpected_70 = &label_Unexpected_70_impl;
      USE(label_Unexpected_70);
      Label label_try_begin_158_202_impl(this);
      Label* label_try_begin_158_202 = &label_try_begin_158_202_impl;
      USE(label_try_begin_158_202);
      Goto(label_try_begin_158_202);
      if (label_try_begin_158_202->is_used())
      {
        BIND(label_try_begin_158_202);
        {
          TNode<JSReceiver> t225 = UncheckedCast<JSReceiver>(TaggedToCallable(p_callback, label_Unexpected_70));
          TVARIABLE(JSReceiver, callbackfn57_impl);
          auto callbackfn57 = &callbackfn57_impl;
          USE(callbackfn57);
          *callbackfn57 = t225;
          TNode<Smi> t226 = UncheckedCast<Smi>(TaggedToSmi(p_initialK, label_Unexpected_70));
          TVARIABLE(Number, k58_impl);
          auto k58 = &k58_impl;
          USE(k58);
          *k58 = t226;
          TNode<Smi> t227 = UncheckedCast<Smi>(TaggedToSmi(p_length, label_Unexpected_70));
          TVARIABLE(Number, number_length59_impl);
          auto number_length59 = &number_length59_impl;
          USE(number_length59);
          *number_length59 = t227;
          TNode<Object> t228 = UncheckedCast<Object>(ArrayForEachTorqueContinuation(p_context, p_object, number_length59->value(), callbackfn57->value(), p_thisArg, k58->value()));
          USE(t228);
          Return(t228);
        }
      }
      if (label_Unexpected_70->is_used())
      {
        BIND(label_Unexpected_70);
        {
          Unreachable();
        }
      }
    }
  }
}

compiler::TNode<Object> ArrayBuiltinsFromDSLAssembler::FastArrayForEach(TNode<Context> p_context, TNode<Object> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout_71, TVariable<Smi>* Bailout060) {
  Node* return_default = &*SmiConstant(0);
  TVARIABLE(Object, _return61_impl);
  auto _return61 = &_return61_impl;
  USE(_return61);
  *_return61 = UncheckedCast<Object>(return_default);
  Label label_macro_end_203_impl(this, {_return61});
  Label* label_macro_end_203 = &label_macro_end_203_impl;
  USE(label_macro_end_203);
  {
    int32_t t229 = 0;
    TVARIABLE(Smi, k62_impl);
    auto k62 = &k62_impl;
    USE(k62);
    TNode<Smi> t230 = UncheckedCast<Smi>(SmiConstant(t229));
    *k62 = t230;
    {
      Label label_try_done_159_204_impl(this);
      Label* label_try_done_159_204 = &label_try_done_159_204_impl;
      USE(label_try_done_159_204);
      Label label_Slow_72_impl(this);
      Label* label_Slow_72 = &label_Slow_72_impl;
      USE(label_Slow_72);
      Label label_try_begin_160_205_impl(this);
      Label* label_try_begin_160_205 = &label_try_begin_160_205_impl;
      USE(label_try_begin_160_205);
      Goto(label_try_begin_160_205);
      if (label_try_begin_160_205->is_used())
      {
        BIND(label_try_begin_160_205);
        {
          TNode<Smi> t231 = UncheckedCast<Smi>(TaggedToSmi(p_len, label_Slow_72));
          TVARIABLE(Smi, smi_len63_impl);
          auto smi_len63 = &smi_len63_impl;
          USE(smi_len63);
          *smi_len63 = t231;
          TNode<JSArray> t232 = UncheckedCast<JSArray>(TaggedToJSArray(p_o, label_Slow_72));
          TVARIABLE(JSArray, a64_impl);
          auto a64 = &a64_impl;
          USE(a64);
          *a64 = t232;
          TNode<Map> t233 = UncheckedCast<Map>(LoadMap(a64->value()));
          TVARIABLE(Map, map65_impl);
          auto map65 = &map65_impl;
          USE(map65);
          *map65 = t233;
          {
            Label label__True_73_impl(this);
            Label* label__True_73 = &label__True_73_impl;
            USE(label__True_73);
            Label label__False_74_impl(this, {});
            Label* label__False_74 = &label__False_74_impl;
            USE(label__False_74);
            TNode<BoolT> t234 = UncheckedCast<BoolT>(IsPrototypeInitialArrayPrototype(p_context, map65->value()));
            USE(t234);
            TNode<BoolT> t235 = UncheckedCast<BoolT>(Word32BinaryNot(t234));
            Branch(t235, label__True_73, label__False_74);
            if (label__True_73->is_used())
            {
              BIND(label__True_73);
              Goto(label_Slow_72);
            }
            BIND(label__False_74);
          }
          TNode<Int32T> t236 = UncheckedCast<Int32T>(LoadMapElementsKind(map65->value()));
          TVARIABLE(Int32T, elementsKind66_impl);
          auto elementsKind66 = &elementsKind66_impl;
          USE(elementsKind66);
          *elementsKind66 = t236;
          {
            Label label__True_75_impl(this);
            Label* label__True_75 = &label__True_75_impl;
            USE(label__True_75);
            Label label__False_76_impl(this, {});
            Label* label__False_76 = &label__False_76_impl;
            USE(label__False_76);
            TNode<BoolT> t237 = UncheckedCast<BoolT>(IsFastElementsKind(elementsKind66->value()));
            USE(t237);
            TNode<BoolT> t238 = UncheckedCast<BoolT>(Word32BinaryNot(t237));
            Branch(t238, label__True_75, label__False_76);
            if (label__True_75->is_used())
            {
              BIND(label__True_75);
              Goto(label_Slow_72);
            }
            BIND(label__False_76);
          }
          {
            Label label__True_77_impl(this);
            Label* label__True_77 = &label__True_77_impl;
            USE(label__True_77);
            Label label__False_78_impl(this);
            Label* label__False_78 = &label__False_78_impl;
            USE(label__False_78);
            Label label_if_done_label_161_206_impl(this, {});
            Label* label_if_done_label_161_206 = &label_if_done_label_161_206_impl;
            USE(label_if_done_label_161_206);
            TNode<BoolT> t239 = UncheckedCast<BoolT>(IsElementsKindGreaterThan(elementsKind66->value(), HOLEY_ELEMENTS));
            USE(t239);
            Branch(t239, label__True_77, label__False_78);
            if (label__True_77->is_used())
            {
              BIND(label__True_77);
              {
                VisitAllElements18ATFixedDoubleArray(p_context, a64->value(), smi_len63->value(), p_callbackfn, p_thisArg, label_Bailout_71, Bailout060);
              }
              Goto(label_if_done_label_161_206);
            }
            if (label__False_78->is_used())
            {
              BIND(label__False_78);
              {
                VisitAllElements12ATFixedArray(p_context, a64->value(), smi_len63->value(), p_callbackfn, p_thisArg, label_Bailout_71, Bailout060);
              }
              Goto(label_if_done_label_161_206);
            }
            BIND(label_if_done_label_161_206);
          }
        }
        Goto(label_try_done_159_204);
      }
      if (label_Slow_72->is_used())
      {
        BIND(label_Slow_72);
        {
          *Bailout060 = k62->value();
          Goto(label_Bailout_71);
        }
      }
      BIND(label_try_done_159_204);
    }
    *_return61 = UndefinedConstant();
    Goto(label_macro_end_203);
  }
  BIND(label_macro_end_203);
  return _return61->value();
}

TF_BUILTIN(ArrayForEach, ArrayBuiltinsFromDSLAssembler) {
  TNode<Context> p_context = UncheckedCast<Context>(Parameter(BuiltinDescriptor::kContext));
  USE(p_context);
  Node* argc = Parameter(BuiltinDescriptor::kArgumentsCount);
  CodeStubArguments arguments_impl(this, ChangeInt32ToIntPtr(argc));
  TNode<Object> p_receiver = arguments_impl.GetReceiver();
  auto arguments = &arguments_impl;
  USE(arguments);
  USE(p_receiver);
  {
    {
      Label label_try_done_162_207_impl(this);
      Label* label_try_done_162_207 = &label_try_done_162_207_impl;
      USE(label_try_done_162_207);
      Label label_TypeError_79_impl(this);
      Label* label_TypeError_79 = &label_TypeError_79_impl;
      USE(label_TypeError_79);
      Label label_NullOrUndefinedError_80_impl(this);
      Label* label_NullOrUndefinedError_80 = &label_NullOrUndefinedError_80_impl;
      USE(label_NullOrUndefinedError_80);
      Label label_try_begin_163_208_impl(this);
      Label* label_try_begin_163_208 = &label_try_begin_163_208_impl;
      USE(label_try_begin_163_208);
      Goto(label_try_begin_163_208);
      if (label_try_begin_163_208->is_used())
      {
        BIND(label_try_begin_163_208);
        {
          {
            Label label__True_81_impl(this);
            Label* label__True_81 = &label__True_81_impl;
            USE(label__True_81);
            Label label__False_82_impl(this, {});
            Label* label__False_82 = &label__False_82_impl;
            USE(label__False_82);
            TNode<BoolT> t240 = UncheckedCast<BoolT>(IsNullOrUndefined(p_receiver));
            USE(t240);
            Branch(t240, label__True_81, label__False_82);
            if (label__True_81->is_used())
            {
              BIND(label__True_81);
              {
                Goto(label_NullOrUndefinedError_80);
              }
            }
            BIND(label__False_82);
          }
          TNode<Object> t241 = UncheckedCast<Object>(CallBuiltin(Builtins::kToObject, p_context, p_receiver));
          USE(t241);
          TVARIABLE(Object, o67_impl);
          auto o67 = &o67_impl;
          USE(o67);
          *o67 = t241;
          TNode<String> t242 = StringConstant("length");
          TNode<Object> t243 = UncheckedCast<Object>(GetProperty(p_context, o67->value(), t242));
          USE(t243);
          TNode<Number> t244 = UncheckedCast<Number>(ToLength_Inline(p_context, t243));
          USE(t244);
          TVARIABLE(Number, len68_impl);
          auto len68 = &len68_impl;
          USE(len68);
          *len68 = t244;
          {
            Label label__True_83_impl(this);
            Label* label__True_83 = &label__True_83_impl;
            USE(label__True_83);
            Label label__False_84_impl(this, {});
            Label* label__False_84 = &label__False_84_impl;
            USE(label__False_84);
            TNode<IntPtrT> t245 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
            int32_t t246 = 0;
            TNode<IntPtrT> t247 = UncheckedCast<IntPtrT>(IntPtrConstant(t246));
            TNode<BoolT> t248 = UncheckedCast<BoolT>(WordEqual(t245, t247));
            Branch(t248, label__True_83, label__False_84);
            if (label__True_83->is_used())
            {
              BIND(label__True_83);
              {
                Goto(label_TypeError_79);
              }
            }
            BIND(label__False_84);
          }
          int32_t t249 = 0;
          TNode<IntPtrT> t250 = UncheckedCast<IntPtrT>(IntPtrConstant(t249));
          TNode<Object> t251 = UncheckedCast<Object>(GetArgumentValue(arguments, t250));
          TNode<JSReceiver> t252 = UncheckedCast<JSReceiver>(TaggedToCallable(t251, label_TypeError_79));
          TVARIABLE(JSReceiver, callbackfn69_impl);
          auto callbackfn69 = &callbackfn69_impl;
          USE(callbackfn69);
          *callbackfn69 = t252;
          auto t253 = [=]() {
            int32_t t255 = 1;
            TNode<IntPtrT> t256 = UncheckedCast<IntPtrT>(IntPtrConstant(t255));
            TNode<Object> t257 = UncheckedCast<Object>(GetArgumentValue(arguments, t256));
            return t257;
          };
          auto t254 = [=]() {
            return UndefinedConstant();
          };
          TVARIABLE(Object, t258164_impl);
          auto t258164 = &t258164_impl;
          USE(t258164);
          {
            Label label__True_85_impl(this);
            Label* label__True_85 = &label__True_85_impl;
            USE(label__True_85);
            Label label__False_86_impl(this);
            Label* label__False_86 = &label__False_86_impl;
            USE(label__False_86);
            Label label__done_165_209_impl(this, {t258164});
            Label* label__done_165_209 = &label__done_165_209_impl;
            USE(label__done_165_209);
            TNode<IntPtrT> t259 = UncheckedCast<IntPtrT>(GetArgumentsLength(arguments));
            int32_t t260 = 1;
            TNode<IntPtrT> t261 = UncheckedCast<IntPtrT>(IntPtrConstant(t260));
            TNode<BoolT> t262 = UncheckedCast<BoolT>(IntPtrGreaterThan(t259, t261));
            Branch(t262, label__True_85, label__False_86);
            BIND(label__True_85);
            *t258164 = t253();
            Goto(label__done_165_209);
            BIND(label__False_86);
            *t258164 = t254();
            Goto(label__done_165_209);
            BIND(label__done_165_209);
          }
          TVARIABLE(Object, thisArg70_impl);
          auto thisArg70 = &thisArg70_impl;
          USE(thisArg70);
          *thisArg70 = t258164->value();
          int32_t t263 = 0;
          TVARIABLE(Number, k71_impl);
          auto k71 = &k71_impl;
          USE(k71);
          TNode<Smi> t264 = UncheckedCast<Smi>(SmiConstant(t263));
          *k71 = t264;
          {
            Label label_try_done_166_210_impl(this);
            Label* label_try_done_166_210 = &label_try_done_166_210_impl;
            USE(label_try_done_166_210);
            Label label_Bailout_87_impl(this);
            Label* label_Bailout_87 = &label_Bailout_87_impl;
            USE(label_Bailout_87);
            TVARIABLE(Smi, k_value72_impl);
            auto k_value72 = &k_value72_impl;
            USE(k_value72);
            Label label_try_begin_167_211_impl(this);
            Label* label_try_begin_167_211 = &label_try_begin_167_211_impl;
            USE(label_try_begin_167_211);
            Goto(label_try_begin_167_211);
            if (label_try_begin_167_211->is_used())
            {
              BIND(label_try_begin_167_211);
              {
                TNode<Object> t265 = UncheckedCast<Object>(FastArrayForEach(p_context, o67->value(), len68->value(), callbackfn69->value(), thisArg70->value(), label_Bailout_87, k_value72));
                USE(t265);
                arguments->PopAndReturn(t265);
              }
            }
            if (label_Bailout_87->is_used())
            {
              BIND(label_Bailout_87);
              {
                *k71 = k_value72->value();
              }
              Goto(label_try_done_166_210);
            }
            BIND(label_try_done_166_210);
          }
          TNode<Object> t266 = UncheckedCast<Object>(ArrayForEachTorqueContinuation(p_context, o67->value(), len68->value(), callbackfn69->value(), thisArg70->value(), k71->value()));
          USE(t266);
          arguments->PopAndReturn(t266);
        }
      }
      if (label_TypeError_79->is_used())
      {
        BIND(label_TypeError_79);
        {
          int32_t t267 = 0;
          TNode<IntPtrT> t268 = UncheckedCast<IntPtrT>(IntPtrConstant(t267));
          TNode<Object> t269 = UncheckedCast<Object>(GetArgumentValue(arguments, t268));
          ThrowTypeError(p_context, MessageTemplate::kCalledNonCallable, t269);
        }
      }
      if (label_NullOrUndefinedError_80->is_used())
      {
        BIND(label_NullOrUndefinedError_80);
        {
          TNode<String> t270 = StringConstant("Array.prototype.forEach");
          ThrowTypeError(p_context, MessageTemplate::kCalledOnNullOrUndefined, t270);
        }
      }
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::VisitAllElements18ATFixedDoubleArray(TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout_140, TVariable<Smi>* Bailout0111) {
  Label label_macro_end_212_impl(this, {});
  Label* label_macro_end_212 = &label_macro_end_212_impl;
  USE(label_macro_end_212);
  {
    int32_t t271 = 0;
    TVARIABLE(Smi, k112_impl);
    auto k112 = &k112_impl;
    USE(k112);
    TNode<Smi> t272 = UncheckedCast<Smi>(SmiConstant(t271));
    *k112 = t272;
    TNode<Map> t273 = UncheckedCast<Map>(LoadMap(p_a));
    TVARIABLE(Map, map113_impl);
    auto map113 = &map113_impl;
    USE(map113);
    *map113 = t273;
    {
      Label label_try_done_168_213_impl(this);
      Label* label_try_done_168_213 = &label_try_done_168_213_impl;
      USE(label_try_done_168_213);
      Label label_Slow_141_impl(this);
      Label* label_Slow_141 = &label_Slow_141_impl;
      USE(label_Slow_141);
      Label label_try_begin_169_214_impl(this);
      Label* label_try_begin_169_214 = &label_try_begin_169_214_impl;
      USE(label_try_begin_169_214);
      Goto(label_try_begin_169_214);
      if (label_try_begin_169_214->is_used())
      {
        BIND(label_try_begin_169_214);
        {
          Label label__True_142_impl(this);
          Label* label__True_142 = &label__True_142_impl;
          USE(label__True_142);
          Label label__False_143_impl(this);
          Label* label__False_143 = &label__False_143_impl;
          USE(label__False_143);
          Label label_header_170_215_impl(this, {k112});
          Label* label_header_170_215 = &label_header_170_215_impl;
          USE(label_header_170_215);
          Goto(label_header_170_215);
          BIND(label_header_170_215);
          Label label_assignment_171_216_impl(this);
          Label* label_assignment_171_216 = &label_assignment_171_216_impl;
          USE(label_assignment_171_216);
          TNode<BoolT> t274 = UncheckedCast<BoolT>(SmiLessThan(k112->value(), p_len));
          Branch(t274, label__True_142, label__False_143);
          if (label__True_142->is_used())
          {
            BIND(label__True_142);
            {
              {
                Label label__True_144_impl(this);
                Label* label__True_144 = &label__True_144_impl;
                USE(label__True_144);
                Label label__False_145_impl(this, {});
                Label* label__False_145 = &label__False_145_impl;
                USE(label__False_145);
                TNode<Map> t275 = UncheckedCast<Map>(LoadMap(p_a));
                TNode<BoolT> t276 = UncheckedCast<BoolT>(WordNotEqual(map113->value(), t275));
                Branch(t276, label__True_144, label__False_145);
                if (label__True_144->is_used())
                {
                  BIND(label__True_144);
                  Goto(label_Slow_141);
                }
                BIND(label__False_145);
              }
              {
                Label label__True_146_impl(this);
                Label* label__True_146 = &label__True_146_impl;
                USE(label__True_146);
                Label label__False_147_impl(this, {});
                Label* label__False_147 = &label__False_147_impl;
                USE(label__False_147);
                TNode<Number> t277 = UncheckedCast<Number>(LoadJSArrayLength(p_a));
                BranchIfNumberGreaterThanOrEqual(k112->value(), t277, label__True_146, label__False_147);
                if (label__True_146->is_used())
                {
                  BIND(label__True_146);
                  Goto(label_Slow_141);
                }
                BIND(label__False_147);
              }
              {
                Label label_try_done_172_217_impl(this);
                Label* label_try_done_172_217 = &label_try_done_172_217_impl;
                USE(label_try_done_172_217);
                Label label_FoundHole_148_impl(this);
                Label* label_FoundHole_148 = &label_FoundHole_148_impl;
                USE(label_FoundHole_148);
                Label label_try_begin_173_218_impl(this);
                Label* label_try_begin_173_218 = &label_try_begin_173_218_impl;
                USE(label_try_begin_173_218);
                Goto(label_try_begin_173_218);
                if (label_try_begin_173_218->is_used())
                {
                  BIND(label_try_begin_173_218);
                  {
                    TNode<Object> t278 = UncheckedCast<Object>(LoadElementNoHole18ATFixedDoubleArray(p_a, k112->value(), label_FoundHole_148));
                    USE(t278);
                    TVARIABLE(Object, value114_impl);
                    auto value114 = &value114_impl;
                    USE(value114);
                    *value114 = t278;
                    TNode<Object> t279 = UncheckedCast<Object>(Call(p_context, p_callbackfn, p_thisArg, value114->value(), k112->value(), p_a));
                    USE(t279);
                  }
                  Goto(label_try_done_172_217);
                }
                if (label_FoundHole_148->is_used())
                {
                  BIND(label_FoundHole_148);
                  {
                    {
                      Label label__True_149_impl(this);
                      Label* label__True_149 = &label__True_149_impl;
                      USE(label__True_149);
                      Label label__False_150_impl(this, {});
                      Label* label__False_150 = &label__False_150_impl;
                      USE(label__False_150);
                      TNode<BoolT> t280 = UncheckedCast<BoolT>(IsNoElementsProtectorCellInvalid());
                      USE(t280);
                      Branch(t280, label__True_149, label__False_150);
                      if (label__True_149->is_used())
                      {
                        BIND(label__True_149);
                        *Bailout0111 = k112->value();
                        Goto(label_Bailout_140);
                      }
                      BIND(label__False_150);
                    }
                  }
                  Goto(label_try_done_172_217);
                }
                BIND(label_try_done_172_217);
              }
            }
            Goto(label_assignment_171_216);
          }
          {
            BIND(label_assignment_171_216);
            int32_t t281 = 1;
            TNode<Smi> t282 = UncheckedCast<Smi>(SmiConstant(t281));
            TNode<Smi> t283 = UncheckedCast<Smi>(SmiAdd(k112->value(), t282));
            *k112 = t283;
            Goto(label_header_170_215);
          }
          BIND(label__False_143);
        }
        Goto(label_try_done_168_213);
      }
      if (label_Slow_141->is_used())
      {
        BIND(label_Slow_141);
        {
          *Bailout0111 = k112->value();
          Goto(label_Bailout_140);
        }
      }
      BIND(label_try_done_168_213);
    }
  }
}

void ArrayBuiltinsFromDSLAssembler::VisitAllElements12ATFixedArray(TNode<Context> p_context, TNode<JSArray> p_a, TNode<Smi> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg, Label* label_Bailout_151, TVariable<Smi>* Bailout0115) {
  Label label_macro_end_219_impl(this, {});
  Label* label_macro_end_219 = &label_macro_end_219_impl;
  USE(label_macro_end_219);
  {
    int32_t t284 = 0;
    TVARIABLE(Smi, k116_impl);
    auto k116 = &k116_impl;
    USE(k116);
    TNode<Smi> t285 = UncheckedCast<Smi>(SmiConstant(t284));
    *k116 = t285;
    TNode<Map> t286 = UncheckedCast<Map>(LoadMap(p_a));
    TVARIABLE(Map, map117_impl);
    auto map117 = &map117_impl;
    USE(map117);
    *map117 = t286;
    {
      Label label_try_done_174_220_impl(this);
      Label* label_try_done_174_220 = &label_try_done_174_220_impl;
      USE(label_try_done_174_220);
      Label label_Slow_152_impl(this);
      Label* label_Slow_152 = &label_Slow_152_impl;
      USE(label_Slow_152);
      Label label_try_begin_175_221_impl(this);
      Label* label_try_begin_175_221 = &label_try_begin_175_221_impl;
      USE(label_try_begin_175_221);
      Goto(label_try_begin_175_221);
      if (label_try_begin_175_221->is_used())
      {
        BIND(label_try_begin_175_221);
        {
          Label label__True_153_impl(this);
          Label* label__True_153 = &label__True_153_impl;
          USE(label__True_153);
          Label label__False_154_impl(this);
          Label* label__False_154 = &label__False_154_impl;
          USE(label__False_154);
          Label label_header_176_222_impl(this, {k116});
          Label* label_header_176_222 = &label_header_176_222_impl;
          USE(label_header_176_222);
          Goto(label_header_176_222);
          BIND(label_header_176_222);
          Label label_assignment_177_223_impl(this);
          Label* label_assignment_177_223 = &label_assignment_177_223_impl;
          USE(label_assignment_177_223);
          TNode<BoolT> t287 = UncheckedCast<BoolT>(SmiLessThan(k116->value(), p_len));
          Branch(t287, label__True_153, label__False_154);
          if (label__True_153->is_used())
          {
            BIND(label__True_153);
            {
              {
                Label label__True_155_impl(this);
                Label* label__True_155 = &label__True_155_impl;
                USE(label__True_155);
                Label label__False_156_impl(this, {});
                Label* label__False_156 = &label__False_156_impl;
                USE(label__False_156);
                TNode<Map> t288 = UncheckedCast<Map>(LoadMap(p_a));
                TNode<BoolT> t289 = UncheckedCast<BoolT>(WordNotEqual(map117->value(), t288));
                Branch(t289, label__True_155, label__False_156);
                if (label__True_155->is_used())
                {
                  BIND(label__True_155);
                  Goto(label_Slow_152);
                }
                BIND(label__False_156);
              }
              {
                Label label__True_157_impl(this);
                Label* label__True_157 = &label__True_157_impl;
                USE(label__True_157);
                Label label__False_158_impl(this, {});
                Label* label__False_158 = &label__False_158_impl;
                USE(label__False_158);
                TNode<Number> t290 = UncheckedCast<Number>(LoadJSArrayLength(p_a));
                BranchIfNumberGreaterThanOrEqual(k116->value(), t290, label__True_157, label__False_158);
                if (label__True_157->is_used())
                {
                  BIND(label__True_157);
                  Goto(label_Slow_152);
                }
                BIND(label__False_158);
              }
              {
                Label label_try_done_178_224_impl(this);
                Label* label_try_done_178_224 = &label_try_done_178_224_impl;
                USE(label_try_done_178_224);
                Label label_FoundHole_159_impl(this);
                Label* label_FoundHole_159 = &label_FoundHole_159_impl;
                USE(label_FoundHole_159);
                Label label_try_begin_179_225_impl(this);
                Label* label_try_begin_179_225 = &label_try_begin_179_225_impl;
                USE(label_try_begin_179_225);
                Goto(label_try_begin_179_225);
                if (label_try_begin_179_225->is_used())
                {
                  BIND(label_try_begin_179_225);
                  {
                    TNode<Object> t291 = UncheckedCast<Object>(LoadElementNoHole12ATFixedArray(p_a, k116->value(), label_FoundHole_159));
                    USE(t291);
                    TVARIABLE(Object, value118_impl);
                    auto value118 = &value118_impl;
                    USE(value118);
                    *value118 = t291;
                    TNode<Object> t292 = UncheckedCast<Object>(Call(p_context, p_callbackfn, p_thisArg, value118->value(), k116->value(), p_a));
                    USE(t292);
                  }
                  Goto(label_try_done_178_224);
                }
                if (label_FoundHole_159->is_used())
                {
                  BIND(label_FoundHole_159);
                  {
                    {
                      Label label__True_160_impl(this);
                      Label* label__True_160 = &label__True_160_impl;
                      USE(label__True_160);
                      Label label__False_161_impl(this, {});
                      Label* label__False_161 = &label__False_161_impl;
                      USE(label__False_161);
                      TNode<BoolT> t293 = UncheckedCast<BoolT>(IsNoElementsProtectorCellInvalid());
                      USE(t293);
                      Branch(t293, label__True_160, label__False_161);
                      if (label__True_160->is_used())
                      {
                        BIND(label__True_160);
                        *Bailout0115 = k116->value();
                        Goto(label_Bailout_151);
                      }
                      BIND(label__False_161);
                    }
                  }
                  Goto(label_try_done_178_224);
                }
                BIND(label_try_done_178_224);
              }
            }
            Goto(label_assignment_177_223);
          }
          {
            BIND(label_assignment_177_223);
            int32_t t294 = 1;
            TNode<Smi> t295 = UncheckedCast<Smi>(SmiConstant(t294));
            TNode<Smi> t296 = UncheckedCast<Smi>(SmiAdd(k116->value(), t295));
            *k116 = t296;
            Goto(label_header_176_222);
          }
          BIND(label__False_154);
        }
        Goto(label_try_done_174_220);
      }
      if (label_Slow_152->is_used())
      {
        BIND(label_Slow_152);
        {
          *Bailout0115 = k116->value();
          Goto(label_Bailout_151);
        }
      }
      BIND(label_try_done_174_220);
    }
  }
}

}  // namepsace internal
}  // namespace v8

