# exam03

// prototype for read: -> ssize_t read(int fd, void buf[count], size_t count);
// prototype for realloc: -> void *realloc(void *ptr, size_t size);
// prototype for memmove: => void *memmove(void dest[n], const void src[n], size_t n);
DECLARE temporary fixed-size array (size BUFFER_SIZE)

DECLARE dynamic pointer result = NULL
DECLARE total_read = 0

LOOP while read() returns more than 0 bytes:

    READ up to BUFFER_SIZE bytes into temp
    STORE number of bytes read into variable bytes

    CALCULATE new required size:
        total_read + bytes + 1  (extra 1 for null terminator)

    REALLOC result to new required size
        IF realloc fails:
            free result
            print error
            EXIT

    COPY bytes from temp
        INTO result starting at index total_read

    INCREASE total_read by bytes

    SET result[total_read] = null terminator
END LOOP


IF last read returned negative value
    print error
    free memory
    EXIT with error

IF result is NULL
    EXIT success

CALL filtering function
FREE result
EXIT success

Build one long string from stdin.

Walk across it with a finger.

At each position:

Try to match target.

If match → print stars and jump.

If no match → print character and move one step.