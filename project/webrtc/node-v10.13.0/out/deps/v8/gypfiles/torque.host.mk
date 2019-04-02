# This file is generated by gyp; do not edit.

TOOLSET := host
TARGET := torque
DEFS_Debug := \
	'-DV8_GYP_BUILD' \
	'-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=0' \
	'-DV8_TARGET_ARCH_X64' \
	'-DV8_EMBEDDER_STRING="-node.36"' \
	'-DENABLE_DISASSEMBLER' \
	'-DV8_PROMISE_INTERNAL_FIELD_COUNT=1' \
	'-DV8_INTL_SUPPORT' \
	'-DV8_CONCURRENT_MARKING' \
	'-DDISABLE_UNTRUSTED_CODE_MITIGATIONS' \
	'-DANTLR4CPP_STATIC' \
	'-DV8_ENABLE_CHECKS' \
	'-DOBJECT_PRINT' \
	'-DVERIFY_HEAP' \
	'-DDEBUG' \
	'-DV8_TRACE_MAPS' \
	'-DV8_ENABLE_ALLOCATION_TIMEOUT' \
	'-DV8_ENABLE_FORCE_SLOW_PATH' \
	'-DENABLE_SLOW_DCHECKS' \
	'-D_DEBUG' \
	'-DENABLE_HANDLE_ZAPPING'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-fno-strict-aliasing \
	-m64 \
	-Woverloaded-virtual \
	 \
	-fdata-sections \
	-ffunction-sections \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-std=gnu++1y

INCS_Debug := \
	-I$(srcdir)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src \
	-I$(srcdir)/deps/v8/src/torque \
	-I$(srcdir)/deps/v8

DEFS_Release := \
	'-DV8_GYP_BUILD' \
	'-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=0' \
	'-DV8_TARGET_ARCH_X64' \
	'-DV8_EMBEDDER_STRING="-node.36"' \
	'-DENABLE_DISASSEMBLER' \
	'-DV8_PROMISE_INTERNAL_FIELD_COUNT=1' \
	'-DV8_INTL_SUPPORT' \
	'-DV8_CONCURRENT_MARKING' \
	'-DDISABLE_UNTRUSTED_CODE_MITIGATIONS' \
	'-DANTLR4CPP_STATIC'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-fno-strict-aliasing \
	-m64 \
	-fdata-sections \
	-ffunction-sections \
	 \
	-O3 \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-std=gnu++1y

INCS_Release := \
	-I$(srcdir)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src \
	-I$(srcdir)/deps/v8/src/torque \
	-I$(srcdir)/deps/v8

OBJS := \
	$(obj).host/$(TARGET)/deps/v8/src/torque/TorqueBaseVisitor.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/TorqueLexer.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/TorqueParser.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/TorqueVisitor.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/ast-generator.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/declarable.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/declaration-visitor.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/declarations.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/file-visitor.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/implementation-visitor.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/scope.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/torque.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/types.o \
	$(obj).host/$(TARGET)/deps/v8/src/torque/utils.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ANTLRErrorListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ANTLRErrorStrategy.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ANTLRFileStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ANTLRInputStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/BailErrorStrategy.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/BaseErrorListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/BufferedTokenStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/CharStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/CommonToken.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/CommonTokenFactory.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/CommonTokenStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ConsoleErrorListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/DefaultErrorStrategy.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/DiagnosticErrorListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/Exceptions.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/FailedPredicateException.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/InputMismatchException.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/IntStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/InterpreterRuleContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/Lexer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/LexerInterpreter.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/LexerNoViableAltException.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ListTokenSource.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/NoViableAltException.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/Parser.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ParserInterpreter.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ParserRuleContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/ProxyErrorListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/RecognitionException.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/Recognizer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/RuleContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/RuleContextWithAltNum.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/RuntimeMetaData.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/Token.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/TokenSource.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/TokenStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/TokenStreamRewriter.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/UnbufferedCharStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/UnbufferedTokenStream.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/Vocabulary.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/WritableToken.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATN.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNConfig.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNConfigSet.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNDeserializationOptions.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNDeserializer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNSerializer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNSimulator.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ATNState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/AbstractPredicateTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ActionTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/AmbiguityInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ArrayPredictionContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/AtomTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/BasicBlockStartState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/BasicState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/BlockEndState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/BlockStartState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ContextSensitivityInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/DecisionEventInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/DecisionInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/DecisionState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/EmptyPredictionContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/EpsilonTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ErrorInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LL1Analyzer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerATNConfig.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerATNSimulator.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerActionExecutor.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerChannelAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerCustomAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerIndexedCustomAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerModeAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerMoreAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerPopModeAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerPushModeAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerSkipAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LexerTypeAction.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LookaheadEventInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/LoopEndState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/NotSetTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/OrderedATNConfigSet.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ParseInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ParserATNSimulator.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PlusBlockStartState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PlusLoopbackState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PrecedencePredicateTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PredicateEvalInfo.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PredicateTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PredictionContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/PredictionMode.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/ProfilingATNSimulator.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/RangeTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/RuleStartState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/RuleStopState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/RuleTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/SemanticContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/SetTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/SingletonPredictionContext.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/StarBlockStartState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/StarLoopEntryState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/StarLoopbackState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/TokensStartState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/Transition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/atn/WildcardTransition.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/dfa/DFA.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/dfa/DFASerializer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/dfa/DFAState.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/dfa/LexerDFASerializer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/misc/InterpreterDataReader.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/misc/Interval.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/misc/IntervalSet.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/misc/MurmurHash.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/misc/Predicate.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/support/Any.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/support/Arrays.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/support/CPPUtils.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/support/StringUtils.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/support/guid.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/ErrorNode.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/ErrorNodeImpl.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/IterativeParseTreeWalker.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/ParseTree.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/ParseTreeListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/ParseTreeVisitor.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/ParseTreeWalker.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/TerminalNode.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/TerminalNodeImpl.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/Trees.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/Chunk.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreeMatch.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreePattern.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/ParseTreePatternMatcher.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/RuleTagToken.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/TagChunk.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/TextChunk.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/pattern/TokenTagToken.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPath.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathElement.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexer.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathLexerErrorListener.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathRuleAnywhereElement.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathRuleElement.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathTokenAnywhereElement.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathTokenElement.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathWildcardAnywhereElement.o \
	$(obj).host/$(TARGET)/deps/v8/third_party/antlr4/runtime/Cpp/runtime/src/tree/xpath/XPathWildcardElement.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).host/deps/v8/gypfiles/libv8_libbase.a

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cpp FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64 \
	-m64

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64 \
	-m64

LIBS := \
	-ldl \
	-lrt

$(builddir)/torque: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(builddir)/torque: LIBS := $(LIBS)
$(builddir)/torque: LD_INPUTS := $(OBJS) $(obj).host/deps/v8/gypfiles/libv8_libbase.a
$(builddir)/torque: TOOLSET := $(TOOLSET)
$(builddir)/torque: $(OBJS) $(obj).host/deps/v8/gypfiles/libv8_libbase.a FORCE_DO_CMD
	$(call do_cmd,link)

all_deps += $(builddir)/torque
# Add target alias
.PHONY: torque
torque: $(builddir)/torque

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/torque

