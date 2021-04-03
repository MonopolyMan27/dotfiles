call plug#begin('~/local/share/nvim/plugged')

" Vim Language Pack
" Plug 'sheerun/vim-polyglot'

" File Explorer
Plug 'scrooloose/NERDTree'

" Auto pairs for '(' '[' '{'
Plug 'jiangmiao/auto-pairs'

" Gruvbox theme
Plug 'morhetz/gruvbox'

" Vim Airline Interface
Plug 'vim-airline/vim-airline'

"Themes for Vim Airline
Plug 'vim-airline/vim-airline-themes'

" Autocomplete
Plug 'vim-scripts/AutoComplPop'

" LaTeX Support
Plug 'lervag/vimtex'

call plug#end()

set termguicolors
set noerrorbells
set smartindent
set nu
set tabstop=4 softtabstop=4
set shiftwidth=4
set expandtab
set nowrap
set smartcase
set incsearch

colorscheme gruvbox
set background=dark

"set colorcolumn=80
"highlight ColorColumn ctermbg=0 guibg=lightgrey

autocmd VimEnter * NERDTree
autocmd VimEnter * wincmd p
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() |
    \ quit | endif

let g:airline_theme = 'gruvbox'
let g:airline#extensions#tabline#enabled = 1

let mapleader=" "
let maplocalleader=" "

set autoindent
set autoread
set backspace=indent,eol,start
set backupdir=/tmp//,.
set clipboard+=unnamedplus
set complete+=kspell
set completeopt=menuone,longest
set cursorline
set directory=/tmp//,.
set encoding=utf-8
set expandtab smarttab
set formatoptions=tcqrn1
set hidden
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set matchpairs+=<:> " Use % to jump between pairs
set mmp=5000
set modelines=2
set nocompatible
set noerrorbells visualbell t_vb=
set noshiftround
set nospell
set nostartofline
set regexpengine=1
set ruler
set scrolloff=3
set shiftwidth=2
set showcmd
set showmatch
set shortmess+=c
set showmode
set smartcase
set softtabstop=2
set spelllang=en_us
set splitbelow
set splitright
set tabstop=2
set textwidth=0
set ttimeout
set timeoutlen=1000
set ttimeoutlen=0
set ttyfast
if !has('nvim')
  set ttymouse=sgr
endif
set undodir=/tmp
set undofile
set virtualedit=block
set whichwrap=b,s,<,>
set wildmenu
set wildmode=full
set wrap

runtime! macros/matchit.vim

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

vmap <C-c> y:call system("xclip -i -selection clipboard", getreg("\""))<CR>:call system("xclip -i", getreg("\""))<CR> 

" transparent bg
"autocmd vimenter * hi Normal guibg=NONE ctermbg=NONE
" For Vim<8, replace EndOfBuffer by NonText
"autocmd vimenter * hi EndOfBuffer guibg=NONE ctermbg=NONE
