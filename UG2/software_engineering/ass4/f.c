#include <stdio.h>
#include <stdlib.h>

enum state {
    START,
    LOOP,
    END,
};

enum events {
    START_LOOPING,
    USERID_MATCHED,
    SHOW_DETAIL,
    STOP_LOOPING,
};

enum state state; // Declare state globally

int valid_id(int id) {
    return (id > 0 && id < 20) ? 1 : 0;
}

int valid_pw(int id, int password) {
    return (password == id * 1000) ? 1 : 0;
}

int show(int id) {
    return id * 100000;
}

void step_state(enum events event);

int main(void) {
    state = START; // Initialize state
    step_state(START_LOOPING);
    return 0;
}

void step_state(enum events event) {
    int cntr = 0;
    int id, password;

    while (1) {
        cntr++;

        switch (state) {
            case START:
                switch (event) {
                    case START_LOOPING: {
                        state = LOOP;
                        if (cntr > 10) {
                            printf("Session expired!\n");
                            event = STOP_LOOPING;
                            state = END;
                        } else {
                            printf("Hello, please provide User Id and Password to see your details!\n");
                            printf("User Id: ");
                            scanf("%d", &id);
                            if (valid_id(id)) {
                                event = USERID_MATCHED;
                            } else {
                                printf("Incorrect User Id!!\n");
                                event = START_LOOPING;
                                state = START;
                            }
                        }
                        break;
                    }
                    case STOP_LOOPING: {
                        printf("Invalid state\n");
                        state = END;
			exit(1);
                    }
                    default:
                        exit(1);
                        break;
                }
                break;

            case LOOP:
                switch (event) {
                    case USERID_MATCHED:
                        printf("Password: ");
                        scanf("%d", &password);
                        if (valid_pw(id, password)) {
                            event = SHOW_DETAIL;
                        } else {
                            printf("Incorrect password!!\n");
                            event = STOP_LOOPING;
                            state = START;
                        }
                        break;

                    case SHOW_DETAIL: {
                        printf("User Id : %d, Password: %d , Amount : %d\n", id, password, show(id));
                        state = START;
                        event = START_LOOPING;
                        break;
                    }

                    default:
                        exit(1);
                        break;
                }
                break;

            case END:
                exit(1);
                break;
        }
    }
}

