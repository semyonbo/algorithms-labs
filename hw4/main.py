import time
import multiprocessing
from threading import Thread
import asyncio


def register_user(user_id, t1):
    time.sleep(t1)

def get_main_page(user_id, t2):
    time.sleep(t2)

def view_users_list(user_id, t3):
    time.sleep(t3)


def sequential_processing(u1, u2, u3, t1, t2, t3):
    for i in range(u1):
        register_user(i, t1)
    for i in range(u2):
        get_main_page(i, t2)
    for i in range(u3):
        view_users_list(i, t3)

def subprocess_processing(u1, u2, u3, t1, t2, t3):
    processes = []
    for i in range(u1):
        p = multiprocessing.Process(target=register_user, args=(i, t1))
        processes.append(p)
        p.start()
    for i in range(u2):
        p = multiprocessing.Process(target=get_main_page, args=(i, t2))
        processes.append(p)
        p.start()
    for i in range(u3):
        p = multiprocessing.Process(target=view_users_list, args=(i, t3))
        processes.append(p)
        p.start()
    for p in processes:
        p.join()

def threads_processing(u1, u2, u3, t1, t2, t3):
    threads = []
    for i in range(u1):
        t = Thread(target=register_user, args=(i, t1))
        threads.append(t)
        t.start()
    for i in range(u2):
        t = Thread(target=get_main_page, args=(i, t2))
        threads.append(t)
        t.start()
    for i in range(u3):
        t = Thread(target=view_users_list, args=(i, t3))
        threads.append(t)
        t.start()
    for t in threads:
        t.join()

async def async_register_user(user_id, t1):
    #print(f"User {user_id} registering...")
    await asyncio.sleep(t1)
    #print(f"User {user_id} finished registration.")

async def async_get_main_page(user_id, t2):
    #print(f"User {user_id} getting main page...")
    await asyncio.sleep(t2)
    #print(f"User {user_id} finished getting main page.")

async def async_view_users_list(user_id, t3):
    #print(f"User {user_id} viewing users list...")
    await asyncio.sleep(t3)
    #print(f"User {user_id} finished viewing users list.")

async def asyncio_processing(u1, u2, u3, t1, t2, t3):
    tasks = []
    for i in range(u1):
        tasks.append(async_register_user(i, t1))
    for i in range(u2):
        tasks.append(async_get_main_page(i, t2))
    for i in range(u3):
        tasks.append(async_view_users_list(i, t3))
    await asyncio.gather(*tasks)

if __name__ == "__main__":
    u1, u2, u3 = 5, 5, 5
    t1, t2, t3 = 1, 0.5, 0.2

    print("Sequential Processing:")
    start_time = time.time()
    sequential_processing(u1, u2, u3, t1, t2, t3)
    duration = time.time() - start_time
    print(f"Time taken: {duration:.2f} seconds")


    print("Threads Processing:")
    start_time = time.time()
    threads_processing(u1, u2, u3, t1, t2, t3)
    duration = time.time() - start_time
    print(f"Time taken: {duration:.2f} seconds")


    print("Subprocess Processing:")
    start_time = time.time()
    subprocess_processing(u1, u2, u3, t1, t2, t3)
    duration = time.time() - start_time
    print(f"Time taken: {duration:.2f} seconds")

    print("Asyncio Processing:")
    start_time = time.time()
    asyncio.run(asyncio_processing(u1, u2, u3, t1, t2, t3))
    duration = time.time() - start_time
    print(f"Time taken: {duration:.2f} seconds")