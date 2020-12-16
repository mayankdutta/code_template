set nocompatible   " Disable vi-compatibility
set t_Co=256
syntax on
filetype off
filetype plugin indent on
set ttyfast

set relativenumber
set showmode                    " always show what mode we're currently editing in
set nowrap                      " don't wrap lines
set smarttab
set tags=tags
set expandtab                   " expand tabs by default (overloadable per file type later)
set shiftround                  " use multiple of shiftwidth when indenting with '<' and '>'
set backspace=indent,eol,start  " allow backspacing over everything in insert mode
set autoindent                  " always set autoindenting on
set copyindent                  " copy the previous indentation on autoindenting
set number                      " always show line numbers
set ignorecase                  " ignore case when searching
set smartcase                   " ignore case if search pattern is all lowercase
set timeout timeoutlen=200 ttimeoutlen=100
set visualbell           " don't beep
set noerrorbells         " don't beep
set autowrite  "Save on buffer switch
set mouse=a

"""" Basic Behavior
set encoding=utf-8      " set encoding to UTF-8 (default was "latin1")
set wildmenu            " visual autocomplete for command menu
set lazyredraw          " redraw screen only when we need to
set showmatch           " highlight matching parentheses / brackets [{()}]
set laststatus=2        " always show statusline (even with only single window)


"""" Tab settings
set softtabstop=4       " backspace after pressing <TAB> will remove up to this many spaces

"""" Search settings
set incsearch           " search as characters are entered
set hlsearch            " highlight matches

"""" Miscellaneous settings that might be worth enabling
set cursorline         " highlight current line

"set background=dark    " configure Vim to use brighter colors
set autoread           " autoreload the file in Vim if it has been changed outside of Vim

""""indenting
:set tabstop=8     " tabs are at proper location
:set expandtab     " don't use actual tab character (ctrl-v)
:set shiftwidth=4  " indenting is 4 spaces
:set autoindent    " turns it on
:set smartindent   " does the right thing (mostly) in programs
:set cindent       " stricter rules for C programs
