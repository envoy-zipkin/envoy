licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_binary",
    "envoy_cc_fuzz_test",
    "envoy_cc_test",
    "envoy_package",
)

envoy_package()

envoy_cc_test(
    name = "backoff_strategy_test",
    srcs = ["backoff_strategy_test.cc"],
    deps = [
        "//source/common/common:backoff_lib",
        "//test/mocks/runtime:runtime_mocks",
    ],
)

envoy_cc_test(
    name = "assert_test",
    srcs = ["assert_test.cc"],
    deps = [
        "//source/common/common:assert_lib",
        "//test/test_common:logging_lib",
    ],
)

envoy_cc_test(
    name = "base64_test",
    srcs = ["base64_test.cc"],
    deps = [
        "//source/common/buffer:buffer_lib",
        "//source/common/common:base64_lib",
    ],
)

envoy_cc_fuzz_test(
    name = "base64_fuzz_test",
    srcs = ["base64_fuzz_test.cc"],
    corpus = "base64_corpus",
    # Fuzzer is stable, no bugs, simple test target; avoid emitting CO2.
    tags = ["no_fuzz"],
    deps = ["//source/common/common:base64_lib"],
)

envoy_cc_fuzz_test(
    name = "utility_fuzz_test",
    srcs = ["utility_fuzz_test.cc"],
    corpus = "utility_corpus",
    # Fuzzer is stable, no bugs, simple test target; avoid emitting CO2.
    tags = ["no_fuzz"],
    deps = ["//source/common/common:utility_lib"],
)

envoy_cc_fuzz_test(
    name = "hash_fuzz_test",
    srcs = ["hash_fuzz_test.cc"],
    corpus = "hash_corpus",
    deps = ["//source/common/common:hash_lib"],
)

envoy_cc_test(
    name = "cleanup_test",
    srcs = ["cleanup_test.cc"],
    deps = ["//source/common/common:cleanup_lib"],
)

envoy_cc_test(
    name = "phantom_test",
    srcs = ["phantom_test.cc"],
    deps = ["//source/common/common:phantom"],
)

envoy_cc_test(
    name = "fmt_test",
    srcs = ["fmt_test.cc"],
    deps = [
        "//source/common/common:fmt_lib",
        "//source/common/common:minimal_logger_lib",
    ],
)

envoy_cc_test(
    name = "hash_test",
    srcs = ["hash_test.cc"],
    deps = ["//source/common/common:hash_lib"],
)

envoy_cc_test(
    name = "hex_test",
    srcs = ["hex_test.cc"],
    deps = ["//source/common/common:hex_lib"],
)

envoy_cc_test(
    name = "log_macros_test",
    srcs = ["log_macros_test.cc"],
    deps = [
        "//source/common/common:minimal_logger_lib",
        "//test/mocks/http:http_mocks",
        "//test/mocks/network:network_mocks",
        "//test/mocks/upstream:upstream_mocks",
    ],
)

envoy_cc_test(
    name = "matchers_test",
    srcs = ["matchers_test.cc"],
    deps = [
        "//source/common/common:matchers_lib",
        "//source/common/config:metadata_lib",
        "//source/common/protobuf:utility_lib",
        "@envoy_api//envoy/api/v2/core:base_cc",
        "@envoy_api//envoy/type/matcher:metadata_cc",
        "@envoy_api//envoy/type/matcher:number_cc",
        "@envoy_api//envoy/type/matcher:string_cc",
    ],
)

envoy_cc_test(
    name = "mutex_tracer_test",
    srcs = ["mutex_tracer_test.cc"],
    deps = [
        "//source/common/common:mutex_tracer_lib",
        "//test/test_common:contention_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "utility_test",
    srcs = ["utility_test.cc"],
    external_deps = [
        "abseil_strings",
    ],
    deps = [
        "//source/common/common:utility_lib",
        "//test/test_common:test_time_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "perf_annotation_test",
    srcs = ["perf_annotation_test.cc"],
    deps = [
        "//source/common/common:perf_annotation_lib",
    ],
)

envoy_cc_test(
    name = "perf_annotation_disabled_test",
    srcs = ["perf_annotation_disabled_test.cc"],
    deps = [
        "//source/common/common:perf_annotation_lib",
    ],
)

envoy_cc_test(
    name = "stack_array_test",
    srcs = ["stack_array_test.cc"],
    deps = [
        "//source/common/common:stack_array",
    ],
)

envoy_cc_test(
    name = "to_lower_table_test",
    srcs = ["to_lower_table_test.cc"],
    deps = ["//source/common/common:to_lower_table_lib"],
)

envoy_cc_test(
    name = "token_bucket_impl_test",
    srcs = ["token_bucket_impl_test.cc"],
    deps = [
        "//source/common/common:token_bucket_impl_lib",
        "//test/test_common:simulated_time_system_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "callback_impl_test",
    srcs = ["callback_impl_test.cc"],
    deps = ["//source/common/common:callback_impl_lib"],
)

envoy_cc_binary(
    name = "utility_speed_test",
    srcs = ["utility_speed_test.cc"],
    external_deps = [
        "abseil_strings",
        "benchmark",
    ],
    deps = [
        "//source/common/common:assert_lib",
        "//source/common/common:utility_lib",
    ],
)

envoy_cc_test(
    name = "lock_guard_test",
    srcs = ["lock_guard_test.cc"],
    deps = [
        "//source/common/common:lock_guard_lib",
        "//source/common/common:thread_lib",
    ],
)

envoy_cc_test(
    name = "thread_id_test",
    srcs = ["thread_id_test.cc"],
    external_deps = ["abseil_hash_testing"],
    deps = [
        "//source/common/common:thread_lib",
        "//test/test_common:thread_factory_for_test_lib",
    ],
)

envoy_cc_test(
    name = "stl_helpers_test",
    srcs = ["stl_helpers_test.cc"],
    deps = [
        "//source/common/common:stl_helpers",
    ],
)
