import socket
from time import sleep

import matplotlib.animation as animation
import matplotlib.pyplot as plt
from matplotlib.widgets import Button

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("127.0.0.1", 8080))


def is_socket_closed(sock: socket.socket) -> bool:
    try:
        # this will try to read bytes without blocking and also without removing them from buffer (peek only)
        data = sock.recv(16, socket.MSG_DONTWAIT | socket.MSG_PEEK)
        if len(data) == 0:
            return True
    except BlockingIOError:
        return False  # socket is open and reading from it would block
    except ConnectionResetError:
        return True  # socket was closed for some other reason
    except Exception as e:
        return False
    return False


fig, ax = plt.subplots()
plt.subplots_adjust(bottom=0.2)  # Space for button

bars = None


def update_plot(_):
    global bars
    data = client.recv(1024).decode().strip()
    client.send(b"OK")  # Tell C++ to send next step

    if not data:
        plt.close()
        print("Closing")
        sleep(2)
        exit(0)

    arr = eval(data)
    ax.clear()
    bars = ax.bar(range(len(arr)), arr, color="blue")
    plt.draw()


# Add a button to step through sorting process
# button_ax = plt.axes([0.4, 0.05, 0.2, 0.075])
# button = Button(button_ax, "Next Step")
# button.on_clicked(update_plot)
# update_plot(None)
# plt.show()

ani = animation.FuncAnimation(fig, update_plot, interval=0)
plt.show()


client.close()
