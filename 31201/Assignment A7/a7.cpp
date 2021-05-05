#include<bits/stdc++.h>
#include<pcap.h>
#include<net/ethernet.h>
#include<netinet/ip.h>
using namespace std;

int tcpcount=0,udpcount=0,icmpcount=0,arpcount=0,ipcount=0;
void packethandler(u_char* userData,const struct pcap_pkthdr* phthdr,const u_char* packet);
int main()
{
	pcap_t* fp;
	char err[PCAP_ERRBUF_SIZE];
	fp=pcap_open_offline("packet.pcap",err);
	if(fp==NULL)
		cout<<"Error"<<err<<endl;
	if(pcap_loop(fp,0,packethandler,NULL)==-1)
		cout<<"Error"<<endl;

	cout<<"ARP Packets: "<<arpcount<<endl;
	cout<<"IP Packets: "<<ipcount<<endl;
	cout<<"TCP Packets: "<<tcpcount<<endl;
	cout<<"UDP Packets: "<<udpcount<<endl;
	cout<<"ICMP Packets: "<<icmpcount<<endl;
	pcap_close(fp);
}
void packethandler(u_char* userData,const struct pcap_pkthdr* phthdr,const u_char* packet)
{
	const struct ether_header* etherheader=(struct ether_header*)packet;
	const struct ip* ipheader;

	if(ntohs(etherheader->ether_type)==ETHERTYPE_IP)
	{
		ipheader=(struct ip*)(packet+sizeof(struct ether_header));
		if(ipheader->ip_p==IPPROTO_TCP)
			tcpcount++;
		else if(ipheader->ip_p==IPPROTO_UDP)
			udpcount++;
		else if(ipheader->ip_p==IPPROTO_ICMP)
			icmpcount++;
		else if(ipheader->ip_p==IPPROTO_IP)
			ipcount++;
	}
	else if(ntohs(etherheader->ether_type)==ETHERTYPE_ARP)
	{
		arpcount++;
	}

}