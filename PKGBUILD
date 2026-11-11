pkgname=counter
pkgver=1.0.0
pkgrel=1
pkgdesc="A small C counter tool with a secret built-in game and achievements"
arch=('x86_64')
url="https://github.com/GdevMan/counter"
license=('MIT')
depends=('glibc')
makedepends=('gcc' 'make')

source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/v$pkgver.tar.gz")
sha256sums=('SKIP')

build() {
    cd "$srcdir/$pkgname-$pkgver"
    make
}

package() {
    cd "$srcdir/$pkgname-$pkgver"

    install -Dm755 counter "$pkgdir/usr/bin/counter"
    install -Dm644 LICENSE \
        "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
