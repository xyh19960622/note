# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := node_perfctr
### Rules for final target.
$(obj).target/node_perfctr.stamp: TOOLSET := $(TOOLSET)
$(obj).target/node_perfctr.stamp:  FORCE_DO_CMD
	$(call do_cmd,touch)

all_deps += $(obj).target/node_perfctr.stamp
# Add target alias
.PHONY: node_perfctr
node_perfctr: $(obj).target/node_perfctr.stamp

# Add target alias to "all" target.
.PHONY: all
all: node_perfctr

