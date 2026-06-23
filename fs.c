#include "fs.h"

/* * Global variable to store the file descriptor of the mounted disk.
 * Initialized to -1 to indicate that no disk is currently mounted.
 */
static int disk_fd = -1;

/* ===================================================================== */
/* Helper Functions                            */
/* ===================================================================== */

/* Find an inode by filename. Returns inode number or -1 if not found. */
int find_inode(const char *filename) {
    // TODO: Implement
    return -1;
}

/* Find a free inode. Returns inode number or -1 if none available. */
int find_free_inode() {
    // TODO: Implement
    return -1;
}

/* Find a free data block. Returns block number or -1 if disk is full. */
int find_free_block() {
    // TODO: Implement
    return -1;
}

/* Mark a specific block as used in the bitmap. */
void mark_block_used(int block_num) {
    // TODO: Implement
}

/* Mark a specific block as free in the bitmap. */
void mark_block_free(int block_num) {
    // TODO: Implement
}

/* Read a specific inode from the disk into the target structure. */
void read_inode(int inode_num, inode *target) {
    // TODO: Implement
}

/* Write a specific inode structure to the disk. */
void write_inode(int inode_num, const inode *source) {
    // TODO: Implement
}


/* ===================================================================== */
/* External Interface                          */
/* ===================================================================== */

// Create or overwrite the virtual disk file
int fs_format(const char *disk_path) {
    // Open the virtual disk file
    int disk_fd = open(disk_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
    
    if (disk_fd == -1) {
        return -1;
    }

    // Initialize and write the superblock
    superblock sb;

    sb.total_blocks = MAX_BLOCKS;
    sb.block_size = BLOCK_SIZE;
    sb.free_blocks = 2550;
    sb.total_inodes = MAX_FILES;
    sb.free_inodes = 256;
    lseek(disk_fd, 0, SEEK_SET);
    write(disk_fd, &sb, sizeof(superblock));

    // Initialize and write the block bitmap
    unsigned char bitmap[BLOCK_SIZE];
    
    memset(bitmap, 0, sizeof(bitmap));
    for (int i = 0; i <= 9; i++) {
        bitmap[i/8] |= (1 << (i%8));
    }
    lseek(disk_fd, BLOCK_SIZE, SEEK_SET);
    write(disk_fd, bitmap, sizeof(bitmap));

    // Initialize and write the empty inode table
    inode inode_table[MAX_FILES];

    memset(inode_table, 0, sizeof(inode_table));
    lseek(disk_fd, 2 * BLOCK_SIZE, SEEK_SET);
    write(disk_fd, inode_table, sizeof(inode_table));

    // Initialize all data blocks as free
    int current_block = 10;

    while (current_block < 2560) {
        char empty_block[BLOCK_SIZE] = {0};

        lseek(disk_fd, current_block * BLOCK_SIZE, SEEK_SET);
        write(disk_fd, empty_block, BLOCK_SIZE);
        current_block++;
    }

    // Close the virtual disk file
    close(disk_fd);
    return 0;
}


int fs_mount(const char *disk_path) {
    disk_fd = open(disk_path, O_RDWR, 0644);
    if (disk_fd == -1) {
        return -1;
    }

    // Read and validate the superblock
    superblock sb;

    lseek(disk_fd, 0, SEEK_SET);
    read(disk_fd, &sb, sizeof(superblock));
    if (sb.block_size != BLOCK_SIZE || sb.total_blocks != MAX_BLOCKS || sb.total_inodes != MAX_FILES)
    {
        close(disk_fd);
        disk_fd = -1;
        return -1;
    }
    
    return 0;
}

void fs_unmount() {
    // TODO: Flush any cached data to disk (if applicable)
    // TODO: Close the virtual disk file
    if (disk_fd != -1) {
        close(disk_fd);
        disk_fd = -1;
    }
}

int fs_create(const char *filename) {
    // TODO: Check if file already exists
    // TODO: Find a free inode
    // TODO: Initialize the inode (set used=1, size=0, copy filename)
    // TODO: Update superblock (decrease free_inodes)
    // TODO: Write updated inode and superblock to disk
    
    return 0; 
}

int fs_delete(const char *filename) {
    // TODO: Find the file's inode
    // TODO: Mark all data blocks used by the file as free in the bitmap
    // TODO: Mark the inode as free
    // TODO: Update superblock (increase free_blocks and free_inodes)
    // TODO: Write updates to disk
    
    return 0;
}

int fs_list(char filenames[][MAX_FILENAME], int max_files) {
    // TODO: Scan the inode table for used inodes
    // TODO: Copy valid filenames to the provided array (up to max_files)
    
    return 0; // Return the number of files found
}

int fs_write(const char *filename, const void *data, int size) {
    // TODO: Find the file's inode
    // TODO: Calculate required blocks and free any previously allocated blocks
    // TODO: Allocate new blocks and update the bitmap
    // TODO: Write data to the allocated blocks
    // TODO: Update the inode (size and pointers)
    // TODO: Update the superblock and write all metadata changes to disk
    
    return 0; // Return 0 on success
}

int fs_read(const char *filename, void *buffer, int size) {
    // TODO: Find the file's inode
    // TODO: Determine how many bytes to actually read
    // TODO: Read data from the file's blocks into the buffer
    
    return 0; // Return number of bytes read
}