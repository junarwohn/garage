# Install uim
echo "Installing uim"
pacman -S uim xorg-xev;
echo "Install done"

read -p "Did you UPDATED your korean language pack by [Search -> Language Support? [y/N]" yn
case $yn in
	[Yy]* ) ;;
	* ) exit;;
esac

echo "Input HANGUL Keycode."
echo "You can find your HANGUL Keycode by runnging"
echo "xev -event keyboard | grep keycode"
echo "And Press your Key."
read hangul_keycode
echo "<${hangul_keycode}>"

echo "Input HANJA Keycode."
read hanja_keycode
echo "<${hanja_keycode}>"

# Backup
cp /usr/share/X11/xkb/keycodes/evdev /usr/share/X11/xkb/keycodes/evdev_backup_$(date +"%Y%m%d_%H%M%S")

# Commenting previous mapped key.
sed -i "s/.*${hangul_keycode};/\/\/&/" /usr/share/X11/xkb/keycodes/evdev
sed -i "s/.*${hanja_keycode};/\/\/&/" /usr/share/X11/xkb/keycodes/evdev

dest_hangul_keycode=$(sed -n "s/.*<HNGL> =\s*//p" /usr/share/X11/xkb/keycodes/evdev | sed -n "s/;.*//p")

# Replace keycode
sed -i "s/<HNGL>.*/<HNGL> = ${hangul_keycode};/" /usr/share/X11/xkb/keycodes/evdev
sed -i "s/<HJCV>.*/<HJCV> = ${hanja_keycode};/" /usr/share/X11/xkb/keycodes/evdev

echo "Installing uim and setting keymap done. Reboot your system and setting the rest in uim"
