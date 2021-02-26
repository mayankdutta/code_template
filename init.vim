set nocompatible   " Disable vi-compatibility
set t_Co=256
syntax on
filetype off
filetype plugin indent on
set ttyfast "helps in fast scrolling of screen

set relativenumber
set showmode                    " always show what mode we're currently editing in
set formatoptions-=cro          " Stop newline continution of comments
set nowrap                      " don't wrap lines
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
set autowrite           "Save on buffer switch
set mouse=a

"""" Basic Behavior
set encoding=utf-8      " set encoding to UTF-8 (default was "latin1")
set wildmenu            " visual autocomplete for command menu
set wildmode=longest,list,full

set lazyredraw          " redraw screen only when we need to, help in fast scrolling of screen
set showmatch           " highlight matching parentheses / brackets [{()}]

""""" status line
set laststatus=2        " enable the status line, if enabled then we can do futher tweaking by set statusline
                        "for futher tweaking refer to https://shapeshed.com/vim-statuslines/
                        "set laststatus=0       " to disable the status line 

set showtabline=2                       " Always show tabs
set cmdheight=2                         " More space for displaying messages

"""" for windows 
"set splitbelow                          " Horizontal splits will automatically be below
"set splitright                          " Vertical splits will automatically be to the right

" Use alt + hjkl to resize windows
nnoremap <M-j>    :resize -2<CR>
nnoremap <M-k>    :resize +2<CR>
nnoremap <M-h>    :vertical resize -2<CR>
nnoremap <M-l>    :vertical resize +2<CR>

" Better window navigation
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l


"""" Tab settings
set softtabstop=4       " backspace after pressing <TAB> will remove up to this many spaces
" TAB in general mode will move to text buffer
"nnoremap <TAB> :bnext<CR>
" SHIFT-TAB will go back
"nnoremap <S-TAB> :bprevious<CR>





"""" Search settings
set incsearch           " search as characters are entered
set hlsearch            " highlight matches

"""" Miscellaneous settings that might be worth enabling
set cursorline         " highlight current line

"set background=dark    " configure Vim to use brighter colors
set autoread           " autoreload the file in Vim if it has been changed outside of Vim

""""indenting
set tabstop=2                           " Insert 2 spaces for a tab
set expandtab     " don't use actual tab character (ctrl-v)
set shiftwidth=2                        " Change the number of space characters inserted for indentation
set autoindent    " turns it on
set smartindent   " does the right thing (mostly) in programs
set cindent       " stricter rules for C programs
set smarttab
set ruler
set conceallevel=0                      " So that I can see `` in markdown files



call plug#begin("~/.vim/plugged")
" Plugin Section

Plug 'scrooloose/nerdtree'
Plug 'ryanoasis/vim-devicons' "for icons 
Plug 'dracula/vim' "theme 
Plug 'rbong/vim-crystalline' "status line 
"Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
"Plug 'junegunn/fzf.vim'
Plug 'sheerun/vim-polyglot' "for js and python better hightlighting

"for node js
Plug 'neoclide/coc.nvim', {'branch': 'release'}
let g:coc_global_extensions = ['coc-emmet', 'coc-css', 'coc-html', 'coc-json', 'coc-prettier', 'coc-tsserver', 'coc-eslint']
"for node js

Plug 'leafgarland/typescript-vim'
Plug 'peitalin/vim-jsx-typescript'
"vim surround as was mentioned in the book
Plug 'tpope/vim-surround'
Plug 'bfrg/vim-cpp-modern' 

"Plug 'bling/vim-airline'


call plug#end()
"Config Section

if (has("termguicolors"))
  set termguicolors
endif
syntax enable

colorscheme dracula
:highlight Comment ctermfg=green " to set comments in green colour

let g:NERDTreeShowHidden = 1
let g:NERDTreeMinimalUI = 1
let g:NERDTreeIgnore = []
let g:NERDTreeStatusline = ''

" Automaticaly close nvim if NERDTree is only thing left open
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
" Toggle
nnoremap <silent> <C-b> :NERDTreeToggle<CR>

tnoremap <Esc> <C-\><C-n>
" start terminal in insert mode
au BufEnter * if &buftype == 'terminal' | :startinsert | endif
" open terminal on ctrl+n
function! OpenTerminal()
  split term://fish
  resize 25
endfunction
nnoremap <c-n> :call OpenTerminal()<CR>


"nnoremap <C-p> :FZF<CR>
"let g:fzf_action = {
      "\ 'ctrl-t': 'tab split',
      "\ 'ctrl-s': 'split',
      "\ 'ctrl-v': 'vsplit'
"\}


"for crystalline
