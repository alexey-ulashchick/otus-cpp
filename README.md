# otus-cpp
Project uses googles Bazel as a building tool [https://www.bazel.build/](https://www.bazel.build/) and Travis as a CI/CD pipeline
[https://travis-ci.org/github/alexey-ulashchick/otus-cpp](https://travis-ci.org/github/alexey-ulashchick/otus-cpp)

Resulting binaries might be found in appropriate bintray:
[https://bintray.com/alexey-ulashchick/otus-cpp](https://bintray.com/alexey-ulashchick/otus-cpp)

### Running tests
```
bazel test --test_output=all //tests
```

### Build binary
```
bazel build //src/main:ip_filter
```

### Run binary
```
./bazel-bin/src/main/ip_filter
```

### Packaging
This step usually does not need to be executed localy and part to [Travis pipeline](https://github.com/alexey-ulashchick/otus-cpp/blob/master/.travis.yml). When need to be executed and build locally version of package should be passed as TRAVIS_BUILD_NUMBER vairable. host_force_python parameter enforses usage of Python 2.X. If Python 3.X is available on maching this parameter might be skipped.
```
bazel build --action_env=TRAVIS_BUILD_NUMBER=15 --host_force_python=PY2 :deb-package
```