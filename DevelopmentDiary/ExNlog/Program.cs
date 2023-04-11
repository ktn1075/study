using NLog;
using NLog.Config;
using NLog.Targets;
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

#if (DEBUG)

            var config = new LoggingConfiguration();

            var consoleTarget = new ColoredConsoleTarget();

            config.AddTarget("console", consoleTarget);

            consoleTarget.Layout = @"${logger} ${message}";

            var rule1 = new LoggingRule("*", LogLevel.Debug, consoleTarget);

            config.LoggingRules.Add(rule1);

            LogManager.Configuration = config;


#endif
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
