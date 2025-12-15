src = files(
    'main.cpp',
    'coord-conv.cpp'
)

incdirs = include_directories('../include')

cli11 = dependency('CLI11')
deps = [ cli11 ]

executable(
    'lv95-converter',
    src,
    dependencies: deps,
    include_directories: incdirs,
    install: true
)
