project(
    'lv95-converter',
    'cpp',
    version: '1.1.2-git',
    license: 'GPL-3.0-or-later',
    default_options: [ 'cpp_std=c++11' ]
)

# Try to get version string from git or use project version if that fails.
git_describe = run_command('git', 'describe', '--tags', '--always', '--dirty=*', check: false)
git_describe_out = git_describe.stdout().strip()

tag = 'v' + meson.project_version()

if git_describe_out != ''
  tag = git_describe_out
endif

conf_data = configuration_data()
conf_data.set('version', tag.substring(1))
conf_data.set('vversion', tag)

cli11 = dependency('CLI11')
deps = [ cli11 ]

incdirs = include_directories('include')

src = []

subdir('Documentation')
subdir('include')
subdir('src')

executable(
    'lv95-converter',
    src,
    dependencies: deps,
    include_directories: incdirs,
    install: true
)

manpage = join_paths(meson.current_build_dir(), 'Documentation/lv95-converter.1')
install_man(manpage)
