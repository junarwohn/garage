sudo pacman-mirrors --country Japan Taiwan China Hong_Kong Indonesia Philippines South_Korea &
sudo pacman -Syyu &
sudo ln -s /usr/share/X11/xorg.conf.d/40-libinput.conf /etc/X11/xorg.conf.d/40-libinput.conf &
sudo ../tap_to_touch/40-libinput.conf > /etc/X11/xorg.conf.d/40-libinput.conf &
cp ../uim_settings/.xprofile ~/.xprofile &
sudo pacman -Sy vim uim --noconfirm &
uim-pref-gtk &
