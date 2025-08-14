/*

Repair the use-after-free defect from Listing 6-4

*/

int closedir(DIR *dirp) {
  close(dirp->d_fd);
  free(dirp->d_buf);
  free(dirp);
  return 0;
}
