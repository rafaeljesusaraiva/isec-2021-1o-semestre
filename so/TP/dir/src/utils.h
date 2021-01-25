#ifndef UTILS_H
#define UTILS_H

// PIPES 
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

// PIPE Principal Servidor
#define FIFO_SRV "tubo"

// PIPE Servidor <-> Cliente
#define FIFO_CLI "cli%d"

// PIPE Cliente <-> Thread
#define FIFO_THR_IN "thr%d_in"      // STDOUT
#define FIFO_THR_OUT "thr%d_out"    // STDIN

#endif // UTILS_H

