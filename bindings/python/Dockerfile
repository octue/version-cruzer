FROM windpioneers/gdal-python:rational-swordtail-gdal-3.10.0-python-3.11-dev

RUN apt-get --yes update && apt-get install --yes --no-install-recommends cmake clang
RUN pipx install poetry==2.1.3 && poetry --version

COPY . /source

RUN make -C /source/bindings/python compile CC=clang CXX=clang++
RUN make -C /source/bindings/python test
