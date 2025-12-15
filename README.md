# LV95 Converter

`lv95-converter` is a command line tool used to convert Swiss LV95 coordinates
to WGS84 and vice versa. The formulas used are the ones provided by
[Swisstopo](https://www.swisstopo.admin.ch/en/home.html) as described in their
document [Formulas and constants for the calculation of the Swiss conformal
cylindrical projection and for the transformation between coordinate
systems](https://www.swisstopo.admin.ch/dam/en/sd-web/c46Fz-MHIc3u/refsys-EN.pdf).

## Installation

### macOS (Homebrew)

1. Add my tap:

```console
$ brew tap tifrueh/mytap
```

2. Install `lv95-converter`:

```console
$ brew tap tifrueh/mytap
```

### Arch Linux (PKGBUILD)

You can find a PKGBUILD file in [my PKGBUILD
repository](https://github.com/tifrueh/PKGBUILDs/tree/main/lv95-converter).
Download it or clone the repository and then use `makepkg` and `pacman` to
install the package as you would an ordinary AUR package.

### Building from Source

0. Install dependency [cli11](https://github.com/CLIUtils/CLI11).

1. Download the latest tarball and extract it.

2. Execute `meson setup build` from inside the source directory to setup the
   project.

3. Execute `meson compile -C build` from inside the source directory to build
   the executable.

4. Execute `meson install -C build` from inside the source directory to install
   the executable and the manpage.

## Additional Information

Please refer to the manual pages for any additional information on the program.

If you want to view the manual pages without installing them, clone the
repository and navigate your terminal to it. You can then use man to display any
manual page contained in the Documentation directory of this repository. This
could be done, for example, like so:

```console
$ man ./Documentation/lv95-converter.1
```
