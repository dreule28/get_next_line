# 📖 get_next_line
Reads a file line by line from any file descriptor, using a static buffer. Handles partial reads, newline terminations, and memory safety.

🛠️ Features
Works with any file descriptor (files, standard input, etc.).

Preserves state between calls using static memory.

Compatible with variable buffer sizes via -D BUFFER_SIZE=n.

▶️ Example
<pre>
#include "get_next_line.h"

int main(void)
{
  int fd = open("sample.txt", O_RDONLY);
  char *line;
  while ((line = get_next_line(fd)) != NULL) 
  {
      printf(">> %s", line);
      free(line);
  }
  close(fd);
  return 0;
}
</pre>
🧪 Compilation
<pre>
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
./gnl
</pre>
