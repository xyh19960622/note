cmd_/home/xyh/webrtc/node-v10.13.0/out/Release/v8_build_config.json := LD_LIBRARY_PATH=/home/xyh/webrtc/node-v10.13.0/out/Release/lib.host:/home/xyh/webrtc/node-v10.13.0/out/Release/lib.target:$$LD_LIBRARY_PATH; export LD_LIBRARY_PATH; cd ../deps/v8/gypfiles; mkdir -p /home/xyh/webrtc/node-v10.13.0/out/Release; python ../tools/testrunner/utils/dump_build_config_gyp.py "/home/xyh/webrtc/node-v10.13.0/out/Release/v8_build_config.json" "dcheck_always_on=0" "is_asan=0" "is_cfi=0" "is_component_build=static_library" "is_debug=Release" "is_gcov_coverage=0" "is_msan=0" "is_tsan=0" "is_ubsan_vptr=0" "target_cpu=x64" "v8_enable_i18n_support=1" "v8_enable_verify_predictable=0" "v8_target_cpu=x64" "v8_use_snapshot=true"