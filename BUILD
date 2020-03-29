load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

pkg_tar(
    name = "helloworld-bin",
    strip_prefix = "/src/main",
    package_dir = "/usr/bin",
    srcs = ["//src/main:helloworld_cli"],
    mode = "0755",
)

pkg_tar(
    name = "debian-data",
    extension = "tar.gz",
    deps = [
        ":helloworld-bin",
    ],
)

pkg_deb(
    name = "deb-package",
    data = ":debian-data",
    package = "helloworld",
    architecture = "amd64",
    built_using = "bazel",
    description = "helloworld package",
    maintainer = "Alexey Ulashchick <a.ulashchick@gmail.com>",
    version = "0.0.$(TRAVIS_BUILD_NUMBER)",
)