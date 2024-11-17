### Part 1: Directory and File Management

1. **Create Directories and Files**:

   ```bash
   cd ~                         # Navigate to the home directory
   mkdir project_files           # Create a new directory
   cd project_files              # Change into the directory
   touch file1.txt file2.txt file3.txt  # Create three text files
   ```

2. **View and List Files**:

   ```bash
   pwd                           # Display the current working directory
   ls                            # List all files in the directory
   ```

3. **Copy and Move Files**:
   ```bash
   cp file1.txt backup_file1.txt # Copy file1.txt to backup_file1.txt
   mkdir -p backup               # Create 'backup' directory if it doesn't exist
   mv backup_file1.txt backup/   # Move backup_file1.txt to the backup directory
   ```

### Part 2: File Content Manipulation

4. **Count Words and Lines**:

   ```bash
   echo "This is sample text for file2.txt" > file2.txt  # Write text into file2.txt
   wc file2.txt                                          # Count lines, words, and characters
   ```

5. **Concatenate Files**:
   ```bash
   cat file3.txt >> file2.txt    # Append the content of file3.txt to file2.txt
   ```

### Part 3: Text Searching and Filtering

6. **Use `grep` for Pattern Matching**:

   ```bash
   grep "test" file2.txt         # Search for the word "test" in file2.txt
   grep -v "test" file2.txt      # Display lines that do not contain "test"
   ```

7. **Regular Expressions**:
   ```bash
   grep "^a" file2.txt           # Find lines that start with "a"
   grep "\\.$" file2.txt         # Search for lines ending with a period
   ```

### Part 4: File Permissions

8. **Modify File Access**:
   ```bash
   chmod 664 file3.txt           # Change permissions: rw-rw-r-- (owner and group can read/write, others can read)
   ls -l                         # Verify the permissions of file3.txt
   ```

### Part 5: String Manipulation and Meta Characters

9. **String Operations**:

   ```bash
   echo -e '#!/bin/bash\n echo "Hello, World!" | wc -c' > script.sh  # Create a script.sh file that prints “Hello, World!” and counts characters
   chmod +x script.sh           # Make script.sh executable
   ./script.sh                  # Run the script

   ls *.txt                     # Use meta characters to list all .txt files
   ```
