using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ExNlog
{
    internal class Program
    {
        private static readonly NLog.Logger _logger = NLog.LogManager.GetCurrentClassLogger();

        static void Main(string[] args)
        {
            while (true)
            {
                Thread.Sleep(500);
                _logger.Info("testsdsfafadsfa");
                _logger.Debug("test defafsdfsfsbug");
                _logger.Info("testsdsfafadsfa");
                _logger.Debug("test defafsdfsfsbug");
                _logger.Info("testsdsfafadsfa");
                _logger.Debug("test defafsdfsfsbug");
                _logger.Info("testsdsfafadsfa");
                _logger.Debug("test defafsdfsfsbug");
                _logger.Info("testsdsfafadsfa");
                _logger.Debug("test defafsdfsfsbug");
                _logger.Info("testsdsfafadsfa");
                _logger.Debug("test defafsdfsfsbug");

            }
        }
    }
}
