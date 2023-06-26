import asyncio
import time

class helpit():
    
    async def helpeve(self, num):
        if num % 2 == 0:
            await self.eve(num)
        else:
            print("odd")

    async def eve(self, num):
        num = num + 2
        await asyncio.sleep(10)
        print(num)

async def main():
    start = time.perf_counter()
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    
    helper = helpit()  # Create an instance of the helpit class
    
    coro = [helper.helpeve(num) for num in nums]  # Call helpeve method on the instance
    await asyncio.gather(*coro)
    
    print(time.perf_counter() - start)

asyncio.run(main())
