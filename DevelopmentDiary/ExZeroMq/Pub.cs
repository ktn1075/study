using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Security.Cryptography.X509Certificates;
using System.Security.Policy;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using ZeroMQ;

class Pub
{
    private readonly string URI = "tcp://127.0.0.1:55545";

    public string processData(string data)
    {
        return data.ToUpper();
    }

    public void Start()
    {
        System.Console.WriteLine("Pub start");

        using(var context = new ZContext())
        using(var publisher = new ZSocket(context, ZSocketType.PUB))
        {
            publisher.Bind(URI);
            Console.WriteLine("Sending messages to subscribers");

            int counter = 1;

            while (true)
            {
                string update = "x";

                update = string.Format("{0} {1}","서울시:종로구", "Message"+ counter);




                using (var updateFrame = new ZFrame(update))
                {
                    try
                    {
                        publisher.Send(updateFrame);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex);
                    }
                }

                counter++;
                Thread.Sleep(1000);
            }
        }
    }
}
