project(
    'lv95-converter',
    'cpp',
    version: '1.1.2',
    license: 'GPL-3.0-or-later',
    default_options: [ 'cpp_std=c++11' ]
)

conf_data = configuration_data()
conf_data.set('version', meson.project_version())
conf_data.set('vversion', 'v' + meson.project_version())

cli11 = dependency('CLI11')
deps = [ cli11 ]

incdirs = include_directories('include', 'configuration-files')

src = []

subdir('configuration-files')
subdir('src')

executable(
    'lv95-converter',
    src,
    dependencies: deps,
    include_directories: incdirs,
    install: true
)

install_man('man/lv95-converter.1')
