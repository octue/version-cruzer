FROM debian:11

RUN echo "deb http://deb.debian.org/debian bullseye-backports main contrib non-free" \
  | tee -a /etc/apt/sources.list
RUN apt-get --yes update && apt-get install --yes --no-install-recommends \
  make python3 python3-dev python3-pip pybind11-dev pipx lsb-release wget software-properties-common gnupg
RUN apt-get --yes update && apt-get install --yes --no-install-recommends cmake -t bullseye-backports
RUN wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh && ./llvm.sh 19 && rm llvm.sh
RUN pipx ensurepath
ENV PATH="/root/.local/bin:${PATH}"
RUN pipx install poetry

COPY . /source

RUN make -C /source/bindings/python compile CC=clang-19 CXX=clang++-19
RUN make -C /source/bindings/python test
