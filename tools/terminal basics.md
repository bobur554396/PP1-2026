# 💻 Terminal Basics for Windows, Linux, and macOS

This guide introduces basic terminal (command line) commands for navigating and managing files on **Windows (CMD/PowerShell)**, **Linux**, and **macOS**.

---

## 🪟 WINDOWS (Command Prompt or PowerShell)

| Command | Description |
|--------|-------------|
| `dir` | List files and folders in current directory |
| `cd` | Show current directory — **CMD only** |
| `pwd` | Show current directory — **PowerShell** |
| `cd foldername` | Change to `foldername` |
| `cd ..` | Move up one level |
| `mkdir foldername` | Create new folder |
| `del filename` | Delete a file |
| `rmdir foldername` | Remove empty folder |
| `rmdir /S foldername` | Remove folder and contents — **CMD only** |
| `Remove-Item -Recurse foldername` | Remove folder and contents — **PowerShell** |
| `cls` | Clear the screen |
| `echo Hello` | Print text to screen |

---

## 🐧 LINUX (Terminal)

| Command | Description |
|--------|-------------|
| `ls` | List files and folders |
| `pwd` | Show current directory |
| `cd foldername` | Change to `foldername` |
| `cd ..` | Move up one level |
| `mkdir foldername` | Create new folder |
| `rm filename` | Delete a file |
| `rm -r foldername` | Remove folder and contents |
| `clear` | Clear the screen |
| `echo "Hello"` | Print text to screen |

---

## 🍏 Mac OS (Terminal)

💡 Mac OS uses the same terminal commands as Linux (based on UNIX):

| Command | Description |
|--------|-------------|
| `ls` | List files and folders |
| `pwd` | Show current directory |
| `cd foldername` | Change to `foldername` |
| `cd ..` | Move up one level |
| `mkdir foldername` | Create new folder |
| `rm filename` | Delete a file |
| `rm -r foldername` | Remove folder and contents |
| `clear` | Clear the screen |
| `echo "Hello"` | Print text to screen |

---

## 📌 Tips for All OS

- Use `Tab` to autocomplete file/folder names.
- Use `↑` and `↓` arrows to access command history.
- Press `Ctrl + C` to cancel a running command.
- Terminal is **case-sensitive** on Linux/macOS.

---

## ✅ Summary

| Action | Windows | Linux/macOS |
|--------|---------|-------------|
| List files | `dir` | `ls` |
| Change folder | `cd folder` | `cd folder` |
| Go back | `cd ..` | `cd ..` |
| Create folder | `mkdir folder` | `mkdir folder` |
| Delete file | `del file` | `rm file` |
| Delete folder | `rmdir /S folder` \* | `rm -r folder` |
| Clear screen | `cls` | `clear` |

> \* CMD syntax. In PowerShell use `Remove-Item -Recurse folder`.

---

Now you are ready to navigate and manage files using the terminal!
