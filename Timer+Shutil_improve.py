from timeit import default_timer as timer
import shutil

def _copyfileobj_patched(fsrc, fdst, length=4):
    """Patches shutil method to hugely improve copy speed"""
    while 1:
        buf = fsrc.read(length)
        if not buf:
            break
        fdst.write(buf)
shutil.copyfileobj = _copyfileobj_patched

start= timer()
#your code here
shutil.copy('C:\\Users\\sharon.babu\\Desktop\\s\\file1.zip', 'C:\\Users\\sharon.babu\\Desktop\\sample\\')
end = timer()
totaltime = (end - start)
print("Time taken:", end-start)