load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

pkg_tar(
    name = "ip_filter_bin",
    strip_prefix = "/src/main",
    package_dir = "/usr/bin",
    srcs = ["//src/main"],
    mode = "0755",
)

pkg_tar(
    name = "debian-data",
    extension = "tar.gz",
    deps = [
        ":ip_filter_bin",
    ],
)

pkg_deb(
    name = "deb-package",
    data = ":debian-data",
    package = "ip_filter",
    architecture = "amd64",
    built_using = "bazel",
    description = "ip_filter package",
    maintainer = "Alexey Ulashchick <a.ulashchick@gmail.com>",
    version_file = ":generate_version_file",
)

genrule(
    name = "generate_version_file",
    outs = ["version_file"],
    cmd = "echo 0.0.$${TRAVIS_BUILD_NUMBER} > $@",
)