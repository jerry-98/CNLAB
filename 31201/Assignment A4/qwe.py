# qwe.py 
# ----------------------------------------------------------------------------------
import os 
os.system("tar -xvf crafter-0.2.tar.gz") 
os.system("cd crafter-0.2") 
os.system("./configure") 
os.system("./autogen.sh") 
os.system("make") 
os.system("make install") 
os.system("ldconfig") 