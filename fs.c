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

int fs_format(const char *disk_path) {
    // TODO: Create or overwrite the virtual disk file
    // TODO: Initialize and write the superblock
    // TODO: Initialize and write the block bitmap
    // TODO: Initialize and write the empty inode table
    
    return 0; // Return 0 on success, -1 on failure
}

int fs_mount(const char *disk_path) {
    // TODO: Open the virtual disk file
    // TODO: Read and validate the superblock
    
    return 0; // Return 0 on success, -1 on failure
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