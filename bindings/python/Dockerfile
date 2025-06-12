FROM windpioneers/gdal-python:modest-heron-gdal-2.4.1-python-3.11-slim

RUN apt-get --yes update && apt-get install --yes --no-install-recommends \
  cmake make python3-venv pybind11-dev pipx \
  lsb-release wget software-properties-common gnupg
RUN wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh && ./llvm.sh 19 && rm llvm.sh
RUN apt-get install --yes --no-install-recommends \
  clang-tools-19 libc++-19-dev libc++abi-19-dev

RUN pipx ensurepath
ENV PATH="/root/.local/bin:${PATH}"
RUN pipx install poetry==2.1.3 --python python3

COPY . /source

RUN make -C /source/bindings/python compile \
  CC=clang-19 CXX=clang++-19 CRUZER_LIBCXX=ON
RUN make -C /source/bindings/python test
