# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := v8_snapshot
### Rules for action "run_mksnapshot":
quiet_cmd__home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot = ACTION generating: "$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc" $@
cmd__home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot = LD_LIBRARY_PATH=$(builddir)/lib.host:$(builddir)/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd $(srcdir)/deps/v8/gypfiles; mkdir -p $(obj).$(TOOLSET)/v8_snapshot/geni; "$(builddir)/mksnapshot" --turbo_instruction_scheduling --startup_src "$(obj).$(TOOLSET)/v8_snapshot/geni/snapshot.cc"

$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: obj := $(abs_obj)
$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: builddir := $(abs_builddir)
$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: TOOLSET := $(TOOLSET)
$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc: $(builddir)/mksnapshot FORCE_DO_CMD
	$(call do_cmd,_home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot)

all_deps += $(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc
action__home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs := $(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.cc


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
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Debug := \
	-I$(srcdir)/deps/v8 \
	-I$(srcdir)/. \
	-I$(obj)/gen

DEFS_Release := \
	'-DV8_GYP_BUILD' \
	'-DV8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=0' \
	'-DV8_TARGET_ARCH_X64' \
	'-DV8_EMBEDDER_STRING="-node.36"' \
	'-DENABLE_DISASSEMBLER' \
	'-DV8_PROMISE_INTERNAL_FIELD_COUNT=1' \
	'-DV8_INTL_SUPPORT' \
	'-DV8_CONCURRENT_MARKING' \
	'-DDISABLE_UNTRUSTED_CODE_MITIGATIONS'

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
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Release := \
	-I$(srcdir)/deps/v8 \
	-I$(srcdir)/. \
	-I$(obj)/gen

OBJS := \
	$(obj).target/$(TARGET)/gen/experimental-extras-libraries.o \
	$(obj).target/$(TARGET)/gen/extras-libraries.o \
	$(obj).target/$(TARGET)/gen/libraries.o \
	$(obj).target/$(TARGET)/deps/v8/src/setup-isolate-deserialize.o \
	$(obj).$(TOOLSET)/$(TARGET)/geni/snapshot.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).target/deps/v8/gypfiles/libv8_base.a $(builddir)/mksnapshot $(obj).target/deps/v8/gypfiles/js2c.stamp

# Make sure our actions/rules run before any of us.
$(OBJS): | $(action__home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
# Build our special outputs first.
$(obj).target/deps/v8/gypfiles/libv8_snapshot.a: | $(action__home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs)

# Preserve order dependency of special output on deps.
$(action__home_xyh_webrtc_node_v10_13_0_deps_v8_gypfiles_v8_gyp_v8_snapshot_target_run_mksnapshot_outputs): | $(obj).target/deps/v8/gypfiles/libv8_base.a $(builddir)/mksnapshot $(obj).target/deps/v8/gypfiles/js2c.stamp

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

LIBS :=

$(obj).target/deps/v8/gypfiles/libv8_snapshot.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/deps/v8/gypfiles/libv8_snapshot.a: LIBS := $(LIBS)
$(obj).target/deps/v8/gypfiles/libv8_snapshot.a: TOOLSET := $(TOOLSET)
$(obj).target/deps/v8/gypfiles/libv8_snapshot.a: $(OBJS) $(obj).target/deps/v8/gypfiles/libv8_base.a FORCE_DO_CMD
	$(call do_cmd,alink_thin)

all_deps += $(obj).target/deps/v8/gypfiles/libv8_snapshot.a
# Add target alias
.PHONY: v8_snapshot
v8_snapshot: $(obj).target/deps/v8/gypfiles/libv8_snapshot.a

# Add target alias to "all" target.
.PHONY: all
all: v8_snapshot

