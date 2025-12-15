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

subdir('Documentation')
subdir('include')
subdir('src')
subdir('test')
