#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

 function _update_ps1() {
     PS1=$(powerline-shell $?)
 }
 
 if [[ $TERM != linux && ! $PROMPT_COMMAND =~ _update_ps1 ]]; then
     PROMPT_COMMAND="_update_ps1; $PROMPT_COMMAND"
 fi

export EDITOR=/usr/bin/nvim
alias net="nmtui"
alias firewall='sudo nft -f /etc/nftables.conf'
alias shutdown='echo Please run as root'
alias reboot='echo Please run as root!'
alias svim='sudoedit'
alias ls='ls --color=auto'
alias ll='ls -l'
alias la='ls -a'
alias py='python3'
PS1='[\u@\h \W]\$ '

force_color_prompt=yes
