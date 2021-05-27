#
# ~/.bashrc
#

force_color_prompt=yes
PS1='\[\033[1;33m\]\u\[\033[1;37m\]@\[\033[1;34m\]\h:\[\033[1;35m\]\w\[\033[1;32m\]\$\[\033[0m\] '
export EDITOR=/usr/bin/nvim
export PATH=/home/henry/Downloads/Discord:$PATH
alias paru="paru --sudo doas --sudoflags --"
alias wheel="imwheel -b 45"
alias qwerty="setxkbmap -layout us"
alias colemak="setxkbmap -layout us -variant colemak"
alias net="nmtui"
alias firewall='doas nft -f /etc/nftables.conf'
alias shutdown='echo Please run as root'
alias reboot='echo Please run as root!'
alias svim='doas nvim'
alias rm='echo Please run as root!'
alias ls='ls --color=auto'
alias ll='ls -l'
alias la='ls -a'
alias py='python3'
