# ft_ls

clone of the `ls` command but has limited options and much slower than the real one.

## Building
Clone the repository and just run `make`

## Running
```
./ft_ls # Display contents of current directory

./ft_ls . .. dir1 # Display contents of specified directories

./ft_ls -a # Show hidden files in dir

./ft_ls -R # Recursively show files in dir and subdirs

./ft_ls -l # Show files in long listing format
```

Flags can all be combined e.g. `./ft_ls -laR`
