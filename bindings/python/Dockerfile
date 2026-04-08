FROM windpioneers/gdal-python:rational-swordtail-gdal-3.10.0-python-3.11-dev

# The base image is Debian bookworm, whose default toolchain is GCC 12 /
# libstdc++ 12. Upstream vendor/core uses `constexpr std::bitset::set()`
# in its regex preprocessor, which is a C++23 library feature (P2417R2)
# only available in libstdc++ 13 and libc++ 16 and newer. Bookworm does
# not package a new enough GCC, but it does ship clang-19 and libc++-19,
# so use those instead.
RUN apt-get --yes update && apt-get --yes install --no-install-recommends \
    cmake clang-19 libc++-19-dev libc++abi-19-dev
RUN pipx install poetry==2.1.3 && poetry --version

COPY . /source

# `-stdlib=libc++` is what makes clang-19 use its own C++23-ready
# standard library instead of the system libstdc++ 12.
RUN make -C /source/bindings/python compile \
    CC=clang-19 CXX=clang++-19 CXXFLAGS=-stdlib=libc++
RUN make -C /source/bindings/python test

RUN sleep 5
RUN sync
RUN sha256sum /source/bindings/python/dist/*.whl
RUN unzip -t /source/bindings/python/dist/*.whl
