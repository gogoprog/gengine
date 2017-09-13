let $PROJECT_ROOT = getcwd()
map <F6> :!gengine-run -d $PROJECT_ROOT/test<CR>
map <F7> :Make -C $PROJECT_ROOT/build config=debug64<CR>
