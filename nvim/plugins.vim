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

colorscheme gruvbox
set background=dark

"set colorcolumn=80
"highlight ColorColumn ctermbg=0 guibg=lightgrey

"autocmd VimEnter * NERDTree
"autocmd VimEnter * wincmd p
"autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() |
"    \ quit | endif

let g:airline_theme = 'gruvbox'
let g:airline#extensions#tabline#enabled = 1
let g:airline_powerline_fonts = 1

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

let mapleader=" "
let maplocalleader=" "
