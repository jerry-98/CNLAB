# abc.py 
# ----------------------------------------------------------------------------------
import os 
os.system("arp") 
os.system("scp /home/mkr/Documents/crafter-0.2.tar.gz root@192.168.17.1:/root/Workspace/3208") 
os.system("scp /home/mkr/qwe.py root@192.168.17.1:/root/Workspace/3208") 
os.system("ssh root@192.168.17.1 cd Workspace/3208 python qwe.py") 
