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
#define FIFO_THR "thr%d"

#endif // UTILS_H

