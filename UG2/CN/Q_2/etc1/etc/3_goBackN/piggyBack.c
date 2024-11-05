#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FRAMES 100

typedef struct {
    int seq_num;
    bool ack_received;
} Frame;

void simulate_transmission(Frame frames[], int n_frames, int window_size) {
    int base = 0;
    int next_seq_num = 0;
    int timeout = 2, i;

    while (base < n_frames) {
        for (i = base; i < base + window_size && i < n_frames; i++) {
            if (!frames[i].ack_received) {
                printf("Sending frame %d\n", frames[i].seq_num);
            }
        }

        for (i = base; i < base + window_size && i < n_frames; i++) {
            if (!frames[i].ack_received) {
                if (rand() % 5 == 0) {
                    printf("Frame %d lost\n", frames[i].seq_num);
                } else {
                    printf("Frame %d received\n", frames[i].seq_num);
                    frames[i].ack_received = true;
                }
            }
        }

        bool piggybacked_ack = false;
        for (i = base; i < base + window_size && i < n_frames; i++) {
            if (!frames[i].ack_received) {
                piggybacked_ack = true;
                break;
            }
        }

        if (piggybacked_ack) {
            printf("Sending piggybacked ACK for frames %d to %d\n", base, base + window_size - 1);
        }

        while (base < n_frames && frames[base].ack_received) {
            base++;
        }
    }
}

int main() {
    srand(time(NULL));

    int n_frames, window_size, i;
    printf("Enter the number of frames: ");
    scanf("%d", &n_frames);
    printf("Enter the sliding window size: ");
    scanf("%d", &window_size);

    if (n_frames <= 0 || window_size <= 0 || n_frames > MAX_FRAMES) {
        printf("Invalid input\n");
        return 1;
    }

    Frame frames[MAX_FRAMES];
    for (i = 0; i < n_frames; i++) {
        frames[i].seq_num = i + 1;
        frames[i].ack_received = false;
    }

    simulate_transmission(frames, n_frames, window_size);

    return 0;
}

    
