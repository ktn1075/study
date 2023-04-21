using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using ZeroMQ;

class Sub
{
    private string url;
    private string patternToSubscribe;
    private string subScriberName;

    public void setSubScriberName(string subScriberName)
    {
        this.subScriberName = subScriberName;
    }

    public Sub(string url, string patternToSubscribe)
    {
        this.url = url;
        this.patternToSubscribe = patternToSubscribe;
    }

    public void listen()
    {
        using (var context = new ZContext())
        using (var subscriber = new ZSocket(context, ZSocketType.SUB))
        {
            subscriber.Connect(url);
            subscriber.Subscribe(patternToSubscribe);
            Console.WriteLine("Subscribing to the url {0} & pattern {1}", url, patternToSubscribe);

            while (true)
            {
                var replyFrame = subscriber.ReceiveFrame();
                string message = replyFrame.ReadString();
                Console.WriteLine("{0} received : {1}", subScriberName, message);
            }

        }
    }
}
