# Maintainer: Chris Baba <cbaba001@comcast.net>

# When updating versions change 'pkgver', 'pkgrel' (if needed), and 'sha256sums.

pkgname=chemcalc
pkgver=0.1.3
pkgrel=1
pkgdesc='A chemical calculator that calculates the amount of reagents to use when making solutions.'
arch=('x86_64')
url='https://github.com/Chris-Baba/ChemCalc'
license=('GPL')

depends=(
    'brotli' 
    'bzip2' 
    'curl' 
    'dbus' 
    'double-conversion' 
    'duktape' 
    'e2fsprogs' 
    'expat' 
    'fontconfig' 
    'freetype2' 
    'gcc-libs' 
    'glib2' 
    'glibc'
    'graphite' 
    'harfbuzz' 
    'icu' 
    'keyutils' 
    'krb5' 
    'libb2' 
    'libcap'
    'libffi' 
    'libglvnd' 
    'libidn2' 
    'libnghttp2' 
    'libnghttp3' 
    'libpng'
    'libproxy' 
    'libpsl' 
    'libssh2' 
    'libunistring' 
    'libx11' 
    'libxau' 
    'libxcb'
    'libxdmcp' 
    'libxkbcommon' 
    'openssl' 
    'pcre2' 
    'qt6-base' 
    'systemd-libs'
    'util-linux-libs' 
    'zlib' 
    'zstd'
    )

makedepends=('cmake')

# source=("https://github.com/Chris-Baba/ChemCalc/archive/refs/tags/v0.1.2.tar.gz")
source=("https://github.com/Chris-Baba/ChemCalc/archive/refs/tags/v${pkgver}.tar.gz")

sha256sums=('c1f1b81829a94e25712522389490c6e5999167553e2c9571f733fcd994a085c9')

build() {
    cmake \
        -B build \
        -S "ChemCalc-${pkgver}" \
        -DCMAKE_BUILD_TYPE:STRING='None' \
        -DCMAKE_INSTALL_PREFIX:PATH='/usr' \
        -Wno-dev
    cmake --build build
}

package() {
    DESTDIR="$pkgdir" cmake --install build    
}
