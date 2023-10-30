project(
    'lv95-converter',
    'cpp',
    version: 'v1.0.5',
    license: 'GPL-3.0-or-later',
    default_options: [ 'cpp_std=c++11' ]
)

cli11 = dependency('cli11')
deps = [ cli11 ]

incdirs = include_directories('include')

src = []

subdir('src')

executable(
    'lv95-converter',
    src,
    dependencies: deps,
    include_directories: incdirs,
    install: true
)

install_man('man/lv95-converter.1')